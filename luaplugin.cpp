#include "luaplugin.h"

#include <xlib.h>

#include <lua.hpp>
#pragma comment(lib, "lua")

#pragma comment(lib, "xlualib")
extern "C" int luaopen_xlualib(lua_State* ls);

#include "info.h"

#include "dlg.h"
using namespace Inner;

using namespace std;

static lua_State*     g_lua = nullptr;  //!< ȫ��Lua����

//! ע��C API�򴰿������Ϣ
static int LUA_C_show_info(lua_State* ls)
  {
  xmsg msg;

  const int argc = lua_gettop(ls);
  if(argc < 1)  return 0;

  lua_getglobal(ls, "tostring");
  for(int i = 1; i <= argc; ++i)
    {
    lua_pushvalue(ls, -1);
    lua_pushvalue(ls, i);
    lua_call(ls, 1, 1);
    if(i > 1) msg << "    ";
    size_t l = 0;
    auto s = luaL_checklstring(ls, -1, &l);
    msg.append(s, l);
    lua_pop(ls, 1);
    }

  if(msg.empty()) return 0;

  show_info(msg.c_str());
  return 0;
  }

extern "C" __declspec(dllexport) void inner_show_info(const char* msg)
  {
  show_info(msg);
  }

void luaplugin_init()
  {
  g_lua = luaL_newstate();
  luaL_openlibs(g_lua);

  lua_State* ls = g_lua;

  lua_pop(ls, lua_gettop(ls));

  //�滻xlog���ض�����Ϣ���
  lua_register(ls, "xlog", LUA_C_show_info);

  luaopen_xlualib(ls);

  lua_pushinteger(ls, (size_t)inner_show_info);
  lua_setglobal(ls, "inner_show_info");

  luaL_dofile(ls, "init.lua");

  lua_pop(ls, lua_gettop(ls));
  }

static string g_thd_arg;                //!< Lua�̲߳���
static HANDLE g_lua_thd = nullptr;      //!< Lua�߳̾��

void luaplugin_free()
  {
  if(g_lua_thd != nullptr &&
     g_lua_thd != INVALID_HANDLE_VALUE)
    {
    TerminateThread(g_lua_thd, 0);
    }
  if(g_lua != nullptr)  lua_close(g_lua);
  }

//! ��ѯLua�����Ƿ�����ʹ�ã�����true��ʾ����ʹ�ã����򷵻�false
static bool luaplugin_check()
  {
  if(g_lua_thd != nullptr &&
     g_lua_thd != INVALID_HANDLE_VALUE &&
     WAIT_OBJECT_0 != WaitForSingleObject(g_lua_thd, 0)
     )
    {
    return false;
    }
  return true;
  }

//! Lua�߳�����ִ���û�����Ҫ��
static DWORD WINAPI luaplugin_thd(PVOID lParam)
  {
  UNREFERENCED_PARAMETER(lParam);
  auto ls = g_lua;
  try
    {
    if(g_thd_arg.empty()) return 0;

    bool isfile = false;
    if(*g_thd_arg.begin() == '@')
      {
      isfile = true;
      g_thd_arg.erase(g_thd_arg.begin());
      }

    const string ln(isfile ? "���ؽű�" : "���нű�");

    try
      {
      lua_pop(ls, lua_gettop(ls));
      bool welldone = true;
      if(isfile)
        {
        if(LUA_OK != luaL_loadfile(ls, g_thd_arg.c_str()))
          {
          welldone = false;
          show_info(xmsg() << "��ȡ�ű��ļ�����" << lua_tostring(ls, -1));
          }
        else
          {
          if(LUA_OK != lua_pcall(ls, 0, LUA_MULTRET, 0))
            {
            welldone = false;
            show_info(xmsg() << "���ؽű��ļ�����" << lua_tostring(ls, -1));
            }
          }
        }
      else
        {
        if(LUA_OK != luaL_loadstring(ls, g_thd_arg.c_str()))
          {
          welldone = false;
          show_info(xmsg() << "���ؽű�����" << lua_tostring(ls, -1));
          }
        else
          {
          if(LUA_OK != lua_pcall(ls, 0, LUA_MULTRET, 0))
            {
            welldone = false;
            show_info(xmsg() << "���нű�����" << lua_tostring(ls, -1));
            }
          }
        }

      show_info("");    //�ָ�ÿ��ִ�е���Ϣ

      //ִ��ʧ������ջ������������ֵ
      if(!welldone) lua_pop(ls, lua_gettop(ls));
      }
    catch(const runtime_error& e)
      {
      show_info(xmsg() << ln << "�쳣 : " << e.what());
      }
    catch(...)
      {
      show_info(xmsg() << ln << "δ֪�쳣");
      }
    }
  catch(const runtime_error& e)
    {
    show_info(xmsg() << "�����̷߳����쳣 : " << e.what());
    }
  catch(...)
    {
    show_info("�����̷߳���δ֪�쳣");
    }
  return 0;
  }

//! ʱ�ӻص����ڼ���Lua�̣߳��޸�֪ͨ
System::Void dlg::TM_Notify_Tick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(g_lua_thd == nullptr || g_lua_thd == INVALID_HANDLE_VALUE)
    {
    LB_notify->Text = "�޽ű�����";
    LB_notify->ForeColor = System::Drawing::Color::Silver;
    return;
    }
  if(WAIT_OBJECT_0 != WaitForSingleObject(g_lua_thd, 0))
    {
    LB_notify->Text = "�ű�������...";
    LB_notify->ForeColor = System::Drawing::Color::Red;
    }
  else
    {
    LB_notify->Text = "�ű����н���";
    LB_notify->ForeColor = System::Drawing::Color::Fuchsia;

    CloseHandle(g_lua_thd);
    g_lua_thd = nullptr;
    }
  }

//! ��Ӧ�û�����Ҫ��ִ��Luaָ���ָ���Ƿ�ȴ��ű����н���
System::Void dlg::dolua(const std::string& script, const bool wait)
  {
  if(!luaplugin_check())
    {
    BT_Hold_Click(this, nullptr);
    if(System::Windows::Forms::DialogResult::Yes !=
       MessageBox::Show(
       "��ǰ�нű��������У��Ƿ���ֹ����?",
       "����",
       System::Windows::Forms::MessageBoxButtons::YesNo,
       System::Windows::Forms::MessageBoxIcon::Warning,
       System::Windows::Forms::MessageBoxDefaultButton::Button2
       ))
      {
      BT_Goon_Click(this, nullptr);
      return;
      }
    TerminateThread(g_lua_thd, 0);
    TM_Notify_Tick(this, nullptr);
    show_info(xmsg() << "�ϴεĹ���:" << g_lua_thd << " �ֱ�ǿ�ƹر�");
    }
  if(script.empty()) return;

  CloseHandle(g_lua_thd);
  g_lua_thd = nullptr;

  //��ʾ�ű�
  if(*script.begin() != '@')
    {
    TB_Lua->Text = gcnew String(script.c_str());
    }

  g_thd_arg = script;
  g_lua_thd = CreateThread(nullptr, 0, luaplugin_thd, nullptr, 0, nullptr);
  if(g_lua_thd == nullptr || g_lua_thd == INVALID_HANDLE_VALUE)
    {
    show_info(xmsg() << "���������߳�ʧ�� : " << (intptr_t)GetLastError());
    }
  TM_Notify_Tick(this, nullptr);
  if(!wait) return;

  const DWORD rets = WaitForSingleObject(g_lua_thd, INFINITE);
  if(WAIT_OBJECT_0 != rets)
    {
    show_info(xmsg() << "�ȴ������߳�ʧ�� : "
                  << (intptr_t)rets << " : " << (intptr_t)GetLastError());
    TerminateThread(g_lua_thd, 0);
    }
  TM_Notify_Tick(this, nullptr);

  CloseHandle(g_lua_thd);
  g_lua_thd = nullptr;
  }
System::Void dlg::dolua(const std::string& script)
  {
  dolua(script, false);
  }

//! �Ϸ��¼�
System::Void dlg::dlg_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(e->Data->GetDataPresent(DataFormats::FileDrop))
    {
    e->Effect = DragDropEffects::Link;
    return;
    }
  if(e->Data->GetDataPresent(DataFormats::Text))
    {
    e->Effect = DragDropEffects::Copy;
    return;
    }
  e->Effect = DragDropEffects::None;
  }
System::Void dlg::dlg_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  if(e->Data->GetDataPresent(DataFormats::FileDrop))
    {
    dolua(
      "@" +
      Str2str(
      ((Array^)e->Data->GetData(DataFormats::FileDrop))->GetValue(0)->ToString()
      )
      );
    }
  else
    {
    dolua(
      Str2str(
      e->Data->GetData(DataFormats::Text)->ToString()
      )
      );
    }
  }

//! ִ���û���д��lua�ű�
System::Void dlg::BT_Lua_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  if(System::String::IsNullOrEmpty(TB_Lua->Text)) return;

  dolua(Str2str(TB_Lua->Text));
  }

System::Void dlg::BT_Clear_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  TB_Lua->Clear();
  }

System::Void dlg::BT_Hold_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  const int st = SuspendThread(g_lua_thd);    //ע��SuspendThread����DWORD������int64�ж�����
  if(st < 0)
    {
    show_info(xmsg() << "��û�пɹ���Ĺ����߳� : " << st);
    return;
    }
  show_info(xmsg() << "����̹߳��� : " << st);

  TM_Notify->Enabled = false;
  LB_notify->Text = "�ű�������...";
  LB_notify->ForeColor = System::Drawing::Color::Peru;
  }

System::Void dlg::BT_Goon_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  const int st = ResumeThread(g_lua_thd);    //ע��ResumeThread����DWORD������int64�ж�����
  if(st < 0)
    {
    show_info(xmsg() << "��û�пɻָ��Ĺ����߳� : " << st);
    return;
    }
  if(st <= 1)
    {
    show_info(xmsg() << "����߳������� : " << st);
    TM_Notify->Enabled = true;
    TM_Notify_Tick(sender, e);
    return;
    }
  show_info(xmsg() << "����߳���Ȼ���� : " << st);
  }

System::Void dlg::BT_Kill_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(luaplugin_check())
    {
    show_info("�ǰû�й����߳̿��Թر�");
    return;
    }
  BT_Hold_Click(sender, e);
  if(System::Windows::Forms::DialogResult::Yes !=
     MessageBox::Show(
     "��ǰ�нű��������У��Ƿ���ֹ����?",
     "����",
     System::Windows::Forms::MessageBoxButtons::YesNo,
     System::Windows::Forms::MessageBoxIcon::Warning
     ))
    {
    BT_Goon_Click(sender, e);
    return;
    }
  TM_Notify->Enabled = true;
  TerminateThread(g_lua_thd, 0);
  CloseHandle(g_lua_thd);
  show_info(xmsg() << "����߳�:" << g_lua_thd << " ��ǿ�ƹر�");
  TM_Notify_Tick(sender, e);
  g_lua_thd = nullptr;
  }