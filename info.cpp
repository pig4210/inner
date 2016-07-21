#include "info.h"

#include <xlib.h>

#include "dlg.h"
using namespace Inner;

static xmsg           g_info;                 //!< 信息输出缓冲
static SysCritical    g_info_cri;             //!< 多线程操作信息输出缓冲同步

void show_info(const char* msg)
  {
  if(msg == nullptr)  return;
  g_info_cri.enter();
  try
    {
    if(!g_info.empty())
      {
      g_info << "\r\n";
      }
    g_info << msg;
    }
  catch(...)
    {

    }
  g_info_cri.leave();
  }
void show_info(const std::string& s)
  {
  show_info(s.c_str());
  }

//! 时钟回调用于提取信息输出缓冲并显示到窗口
System::Void dlg::TM_Info_Tick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(g_info.empty())  return;
  g_info_cri.enter();
  try
    {
    if(!g_info.empty())
      {
      if(!System::String::IsNullOrEmpty(TB_Info->Text))
        {
        TB_Info->AppendText("\r\n");
        }
      TB_Info->AppendText(gcnew System::String(g_info.c_str()));
      g_info.clear();
      }
    }
  catch(...)
    {

    }
  g_info_cri.leave();
  }

//! 文本清空
System::Void dlg::TB_Info_DoubleClick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  TB_Info->Clear();
  }
