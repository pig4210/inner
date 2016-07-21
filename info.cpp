#include "info.h"

#include <xlib.h>

#include "dlg.h"
using namespace Inner;

static xmsg           g_info;                 //!< ��Ϣ�������
static SysCritical    g_info_cri;             //!< ���̲߳�����Ϣ�������ͬ��

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

//! ʱ�ӻص�������ȡ��Ϣ������岢��ʾ������
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

//! �ı����
System::Void dlg::TB_Info_DoubleClick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  TB_Info->Clear();
  }
