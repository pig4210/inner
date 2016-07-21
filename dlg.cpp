#include "dlg.h"

#include <string>

#include <gcroot.h>

#include <xlib.h>

#include "luaplugin.h"

static const wchar_t* const gk_app_name = L"inner";
static const wchar_t* const gk_app_ver = L"ver 0.1";
static const wchar_t* const gk_author = L"by triones";
static const wchar_t* const gk_copyright = L"All rights reserved (c)";

using namespace std;
using namespace Inner;

//! �߳�����ʹ���DLL�ɹ�����CLR����
static gcroot <dlg^> mydlg = nullptr;
DWORD WINAPI StartCLR(PVOID lParam)
  {
  UNREFERENCED_PARAMETER(lParam);
  mydlg = gcnew dlg;
  mydlg->ShowDialog();
  return 0;
  }

string dlg::Str2str(String^ text)
  {
  const char* str = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text);
  const string ss(str);
  System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)str);
  return ss;
  }

//! ���ڼ��س�ʼ��
System::Void dlg::dlg_Load(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  wchar_t procname[MAX_PATH];
  GetModuleFileNameW(nullptr, procname, _countof(procname));

  //������
  wstring title;
  title += procname;
  title += L"--";
  title += gk_app_name;
  title += L"  ";
  title += gk_app_ver;
  title += L"  ";
  title += gk_author;
  title += L"  ";
  title += gk_copyright;
  this->Text = gcnew System::String(title.c_str());


  xmsg msg;
  msg << (intptr_t)GetCurrentProcessId();
  LB_Pos->Text = gcnew System::String(s2ws(msg).c_str());

  luaplugin_init();
  }

System::Void dlg::dlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  luaplugin_free();
  }

//! ���ڹر�
System::Void dlg::Btn_Close_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  Close();
  }

//! ������С��
System::Void dlg::Btn_Min_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  this->WindowState = FormWindowState::Minimized;
  }

//! �����ƶ�
System::Void dlg::LB_Pos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  ReleaseCapture();
  SendMessage((HWND)this->Handle.ToPointer(), WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
  }
