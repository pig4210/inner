#pragma once
#include <string>

namespace Inner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// dlg 摘要
	/// </summary>
	public ref class dlg : public System::Windows::Forms::Form
	{
	public:
		dlg(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~dlg()
		{
			if (components)
			{
				delete components;
			}
		}

  protected:

  private: System::Windows::Forms::GroupBox^  GB_Main;
  private: System::Windows::Forms::Button^  BT_Lua;

  private: System::Windows::Forms::Label^  LB_notify;




  public: System::Windows::Forms::TextBox^  TB_Info;
  private:

  private: System::Windows::Forms::Button^  Btn_Close;
  public:
  private: System::Windows::Forms::Button^  Btn_Min;
  private: System::Windows::Forms::Label^  LB_Pos;
  private: System::Windows::Forms::ToolTip^  tp;
  private: System::Windows::Forms::Panel^  PL_Title;
  private: System::Windows::Forms::Panel^  PL_Control;
  private: System::Windows::Forms::TextBox^  TB_Lua;
  private: System::Windows::Forms::Timer^  TM_Info;
  private: System::Windows::Forms::Timer^  TM_Notify;
  private: System::Windows::Forms::Button^  BT_Kill;
  private: System::Windows::Forms::Button^  BT_Goon;
  private: System::Windows::Forms::Button^  BT_Hold;
  private: System::Windows::Forms::Button^  BT_Clear;




  private: System::ComponentModel::IContainer^  components;

  private:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
    this->components = (gcnew System::ComponentModel::Container());
    System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(dlg::typeid));
    this->GB_Main = (gcnew System::Windows::Forms::GroupBox());
    this->BT_Kill = (gcnew System::Windows::Forms::Button());
    this->BT_Goon = (gcnew System::Windows::Forms::Button());
    this->BT_Hold = (gcnew System::Windows::Forms::Button());
    this->BT_Clear = (gcnew System::Windows::Forms::Button());
    this->BT_Lua = (gcnew System::Windows::Forms::Button());
    this->LB_notify = (gcnew System::Windows::Forms::Label());
    this->TB_Info = (gcnew System::Windows::Forms::TextBox());
    this->Btn_Close = (gcnew System::Windows::Forms::Button());
    this->Btn_Min = (gcnew System::Windows::Forms::Button());
    this->LB_Pos = (gcnew System::Windows::Forms::Label());
    this->tp = (gcnew System::Windows::Forms::ToolTip(this->components));
    this->PL_Title = (gcnew System::Windows::Forms::Panel());
    this->PL_Control = (gcnew System::Windows::Forms::Panel());
    this->TB_Lua = (gcnew System::Windows::Forms::TextBox());
    this->TM_Info = (gcnew System::Windows::Forms::Timer(this->components));
    this->TM_Notify = (gcnew System::Windows::Forms::Timer(this->components));
    this->GB_Main->SuspendLayout();
    this->PL_Title->SuspendLayout();
    this->PL_Control->SuspendLayout();
    this->SuspendLayout();
    // 
    // GB_Main
    // 
    this->GB_Main->Controls->Add(this->BT_Kill);
    this->GB_Main->Controls->Add(this->BT_Goon);
    this->GB_Main->Controls->Add(this->BT_Hold);
    this->GB_Main->Controls->Add(this->BT_Clear);
    this->GB_Main->Controls->Add(this->BT_Lua);
    this->GB_Main->Controls->Add(this->LB_notify);
    this->GB_Main->Dock = System::Windows::Forms::DockStyle::Top;
    this->GB_Main->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->GB_Main->ForeColor = System::Drawing::Color::Silver;
    this->GB_Main->Location = System::Drawing::Point(0, 0);
    this->GB_Main->Name = L"GB_Main";
    this->GB_Main->Size = System::Drawing::Size(597, 42);
    this->GB_Main->TabIndex = 0;
    this->GB_Main->TabStop = false;
    this->GB_Main->Text = L"控制面板";
    // 
    // BT_Kill
    // 
    this->BT_Kill->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->BT_Kill->FlatAppearance->BorderSize = 0;
    this->BT_Kill->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
    this->BT_Kill->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                         static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
    this->BT_Kill->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->BT_Kill->Location = System::Drawing::Point(388, 14);
    this->BT_Kill->Name = L"BT_Kill";
    this->BT_Kill->Size = System::Drawing::Size(88, 22);
    this->BT_Kill->TabIndex = 8;
    this->BT_Kill->Text = L"结束脚本";
    this->BT_Kill->UseVisualStyleBackColor = false;
    this->BT_Kill->Click += gcnew System::EventHandler(this, &dlg::BT_Kill_Click);
    // 
    // BT_Goon
    // 
    this->BT_Goon->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->BT_Goon->FlatAppearance->BorderSize = 0;
    this->BT_Goon->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
    this->BT_Goon->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                         static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
    this->BT_Goon->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->BT_Goon->Location = System::Drawing::Point(294, 14);
    this->BT_Goon->Name = L"BT_Goon";
    this->BT_Goon->Size = System::Drawing::Size(88, 22);
    this->BT_Goon->TabIndex = 7;
    this->BT_Goon->Text = L"恢复脚本";
    this->BT_Goon->UseVisualStyleBackColor = false;
    this->BT_Goon->Click += gcnew System::EventHandler(this, &dlg::BT_Goon_Click);
    // 
    // BT_Hold
    // 
    this->BT_Hold->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->BT_Hold->FlatAppearance->BorderSize = 0;
    this->BT_Hold->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
    this->BT_Hold->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                         static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
    this->BT_Hold->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->BT_Hold->Location = System::Drawing::Point(200, 14);
    this->BT_Hold->Name = L"BT_Hold";
    this->BT_Hold->Size = System::Drawing::Size(88, 22);
    this->BT_Hold->TabIndex = 6;
    this->BT_Hold->Text = L"挂起脚本";
    this->BT_Hold->UseVisualStyleBackColor = false;
    this->BT_Hold->Click += gcnew System::EventHandler(this, &dlg::BT_Hold_Click);
    // 
    // BT_Clear
    // 
    this->BT_Clear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                 static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->BT_Clear->FlatAppearance->BorderSize = 0;
    this->BT_Clear->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
    this->BT_Clear->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                          static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
    this->BT_Clear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->BT_Clear->Location = System::Drawing::Point(106, 14);
    this->BT_Clear->Name = L"BT_Clear";
    this->BT_Clear->Size = System::Drawing::Size(88, 22);
    this->BT_Clear->TabIndex = 5;
    this->BT_Clear->Text = L"清除脚本";
    this->BT_Clear->UseVisualStyleBackColor = false;
    this->BT_Clear->Click += gcnew System::EventHandler(this, &dlg::BT_Clear_Click);
    // 
    // BT_Lua
    // 
    this->BT_Lua->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                               static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->BT_Lua->FlatAppearance->BorderSize = 0;
    this->BT_Lua->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
    this->BT_Lua->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                        static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
    this->BT_Lua->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->BT_Lua->Location = System::Drawing::Point(12, 14);
    this->BT_Lua->Name = L"BT_Lua";
    this->BT_Lua->Size = System::Drawing::Size(88, 22);
    this->BT_Lua->TabIndex = 4;
    this->BT_Lua->Text = L"执行脚本(&E)";
    this->BT_Lua->UseVisualStyleBackColor = false;
    this->BT_Lua->Click += gcnew System::EventHandler(this, &dlg::BT_Lua_Click);
    // 
    // LB_notify
    // 
    this->LB_notify->AutoSize = true;
    this->LB_notify->Location = System::Drawing::Point(491, 19);
    this->LB_notify->Name = L"LB_notify";
    this->LB_notify->Size = System::Drawing::Size(65, 12);
    this->LB_notify->TabIndex = 0;
    this->LB_notify->Text = L"无脚本运行";
    // 
    // TB_Info
    // 
    this->TB_Info->BackColor = System::Drawing::Color::Black;
    this->TB_Info->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->TB_Info->Cursor = System::Windows::Forms::Cursors::Arrow;
    this->TB_Info->Dock = System::Windows::Forms::DockStyle::Bottom;
    this->TB_Info->ForeColor = System::Drawing::Color::Silver;
    this->TB_Info->HideSelection = false;
    this->TB_Info->Location = System::Drawing::Point(0, 357);
    this->TB_Info->Multiline = true;
    this->TB_Info->Name = L"TB_Info";
    this->TB_Info->ReadOnly = true;
    this->TB_Info->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->TB_Info->Size = System::Drawing::Size(597, 368);
    this->TB_Info->TabIndex = 1;
    this->tp->SetToolTip(this->TB_Info, L"双击清除");
    this->TB_Info->DoubleClick += gcnew System::EventHandler(this, &dlg::TB_Info_DoubleClick);
    // 
    // Btn_Close
    // 
    this->Btn_Close->BackColor = System::Drawing::Color::Brown;
    this->Btn_Close->Dock = System::Windows::Forms::DockStyle::Left;
    this->Btn_Close->FlatAppearance->BorderSize = 0;
    this->Btn_Close->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Fuchsia;
    this->Btn_Close->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
    this->Btn_Close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->Btn_Close->Location = System::Drawing::Point(0, 0);
    this->Btn_Close->Name = L"Btn_Close";
    this->Btn_Close->Size = System::Drawing::Size(32, 10);
    this->Btn_Close->TabIndex = 2;
    this->Btn_Close->Text = L"&X";
    this->Btn_Close->TextAlign = System::Drawing::ContentAlignment::TopLeft;
    this->tp->SetToolTip(this->Btn_Close, L"关闭(X)");
    this->Btn_Close->UseVisualStyleBackColor = false;
    this->Btn_Close->Click += gcnew System::EventHandler(this, &dlg::Btn_Close_Click);
    // 
    // Btn_Min
    // 
    this->Btn_Min->BackColor = System::Drawing::Color::Goldenrod;
    this->Btn_Min->Dock = System::Windows::Forms::DockStyle::Left;
    this->Btn_Min->FlatAppearance->BorderSize = 0;
    this->Btn_Min->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
    this->Btn_Min->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
    this->Btn_Min->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->Btn_Min->Location = System::Drawing::Point(32, 0);
    this->Btn_Min->Name = L"Btn_Min";
    this->Btn_Min->Size = System::Drawing::Size(32, 10);
    this->Btn_Min->TabIndex = 3;
    this->Btn_Min->Text = L"&N";
    this->Btn_Min->TextAlign = System::Drawing::ContentAlignment::TopLeft;
    this->tp->SetToolTip(this->Btn_Min, L"最小化(N)");
    this->Btn_Min->UseVisualStyleBackColor = false;
    this->Btn_Min->Click += gcnew System::EventHandler(this, &dlg::Btn_Min_Click);
    // 
    // LB_Pos
    // 
    this->LB_Pos->BackColor = System::Drawing::Color::DimGray;
    this->LB_Pos->Dock = System::Windows::Forms::DockStyle::Fill;
    this->LB_Pos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->LB_Pos->Font = (gcnew System::Drawing::Font(L"宋体", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
      static_cast<System::Byte>(134)));
    this->LB_Pos->Location = System::Drawing::Point(0, 0);
    this->LB_Pos->Name = L"LB_Pos";
    this->LB_Pos->Size = System::Drawing::Size(597, 10);
    this->LB_Pos->TabIndex = 4;
    this->LB_Pos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
    this->tp->SetToolTip(this->LB_Pos, L"拖拽移动窗口");
    this->LB_Pos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &dlg::LB_Pos_MouseDown);
    // 
    // tp
    // 
    this->tp->AutomaticDelay = 0;
    this->tp->AutoPopDelay = 2000;
    this->tp->BackColor = System::Drawing::Color::Gold;
    this->tp->ForeColor = System::Drawing::Color::Black;
    this->tp->InitialDelay = 500;
    this->tp->IsBalloon = true;
    this->tp->ReshowDelay = 0;
    // 
    // PL_Title
    // 
    this->PL_Title->Controls->Add(this->Btn_Min);
    this->PL_Title->Controls->Add(this->Btn_Close);
    this->PL_Title->Controls->Add(this->LB_Pos);
    this->PL_Title->Dock = System::Windows::Forms::DockStyle::Top;
    this->PL_Title->Location = System::Drawing::Point(0, 0);
    this->PL_Title->Margin = System::Windows::Forms::Padding(0);
    this->PL_Title->Name = L"PL_Title";
    this->PL_Title->Size = System::Drawing::Size(597, 10);
    this->PL_Title->TabIndex = 5;
    // 
    // PL_Control
    // 
    this->PL_Control->Controls->Add(this->TB_Lua);
    this->PL_Control->Controls->Add(this->GB_Main);
    this->PL_Control->Dock = System::Windows::Forms::DockStyle::Fill;
    this->PL_Control->Location = System::Drawing::Point(0, 10);
    this->PL_Control->Name = L"PL_Control";
    this->PL_Control->Size = System::Drawing::Size(597, 347);
    this->PL_Control->TabIndex = 6;
    // 
    // TB_Lua
    // 
    this->TB_Lua->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                               static_cast<System::Int32>(static_cast<System::Byte>(40)));
    this->TB_Lua->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->TB_Lua->Dock = System::Windows::Forms::DockStyle::Fill;
    this->TB_Lua->ForeColor = System::Drawing::Color::Silver;
    this->TB_Lua->Location = System::Drawing::Point(0, 42);
    this->TB_Lua->Multiline = true;
    this->TB_Lua->Name = L"TB_Lua";
    this->TB_Lua->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->TB_Lua->Size = System::Drawing::Size(597, 305);
    this->TB_Lua->TabIndex = 1;
    // 
    // TM_Info
    // 
    this->TM_Info->Enabled = true;
    this->TM_Info->Tick += gcnew System::EventHandler(this, &dlg::TM_Info_Tick);
    // 
    // TM_Notify
    // 
    this->TM_Notify->Enabled = true;
    this->TM_Notify->Interval = 1000;
    this->TM_Notify->Tick += gcnew System::EventHandler(this, &dlg::TM_Notify_Tick);
    // 
    // dlg
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::Black;
    this->ClientSize = System::Drawing::Size(597, 725);
    this->Controls->Add(this->PL_Control);
    this->Controls->Add(this->PL_Title);
    this->Controls->Add(this->TB_Info);
    this->ForeColor = System::Drawing::Color::Silver;
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
    this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
    this->MaximizeBox = false;
    this->Name = L"dlg";
    this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &dlg::dlg_FormClosed);
    this->Load += gcnew System::EventHandler(this, &dlg::dlg_Load);
    this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::dlg_DragDrop);
    this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::dlg_DragEnter);
    this->GB_Main->ResumeLayout(false);
    this->GB_Main->PerformLayout();
    this->PL_Title->ResumeLayout(false);
    this->PL_Control->ResumeLayout(false);
    this->PL_Control->PerformLayout();
    this->ResumeLayout(false);
    this->PerformLayout();

      }
#pragma endregion
  private: System::Void dolua(const std::string& script, const bool wait);
  private: System::Void dolua(const std::string& script);
  private: std::string dlg::Str2str(String^ text);

  private: System::Void dlg_Load(System::Object^  sender, System::EventArgs^  e);
  private: System::Void dlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
  private: System::Void Btn_Close_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void Btn_Min_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void LB_Pos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

  private: System::Void TB_Info_DoubleClick(System::Object^  sender, System::EventArgs^  e);
  private: System::Void TM_Info_Tick(System::Object^  sender, System::EventArgs^  e);
  private: System::Void TM_Notify_Tick(System::Object^  sender, System::EventArgs^  e);

  private: System::Void dlg_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
  private: System::Void dlg_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);

  private: System::Void BT_Lua_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void BT_Clear_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void BT_Hold_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void BT_Goon_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void BT_Kill_Click(System::Object^  sender, System::EventArgs^  e);
};
}
