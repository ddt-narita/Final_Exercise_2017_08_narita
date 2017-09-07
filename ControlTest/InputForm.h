#pragma once

namespace ControlTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// InputForm の概要
	/// </summary>
	public ref class InputForm : public System::Windows::Forms::Form
	{
	public:
		InputForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~InputForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxValue;
	protected:
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::Button^  buttonOK;


	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(113, 45);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 0;
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(57, 48);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(17, 12);
			this->labelValue->TabIndex = 1;
			this->labelValue->Text = L"値";
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(94, 91);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 2;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &InputForm::button1_Click);
			// 
			// InputForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 135);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->textBoxValue);
			this->Name = L"InputForm";
			this->Text = L"InputForm";
			this->Load += gcnew System::EventHandler(this, &InputForm::InputForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ value;


	private: System::Void InputForm_Load(System::Object^  sender, System::EventArgs^  e) {
		textBoxValue->Text = this->value;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->value = textBoxValue->Text;
		this->Close();
	}
	};
}
