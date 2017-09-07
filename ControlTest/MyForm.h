#pragma once
#include "InputForm.h"
#include <map>

namespace ControlTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button2;








	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(473, 351);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::pictureBox1_DoubleClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 17);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"BitMap";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::BitMapButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(629, 440);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int rowN = 80;		//行数
		int colN = 20;		//列数
		int rectHigh = 20;	//セルの高さ
		int rectWidth = 60;	//セルの幅
		
		ref class selectedCell {

		};

		//各セルの情報を格納するマップ
		std::map<std::string, std::string> *valueMap;

		//行と列の価からマップに配置するキーを作成
		String^ coordinateString(int rowN, int colN) {
			String^ ret = rowN.ToString() + ":" + colN.ToString();
			return ret;
		}

private: System::Void BitMapButton_Click(System::Object^  sender, System::EventArgs^  e) {	

	this->SuspendLayout();

	this->pictureBox1->Size = System::Drawing::Size(colN * rectWidth, rowN * rectHigh);

	//描画先とするImageオブジェクトを作成する
	Bitmap^ canvas = gcnew Bitmap(pictureBox1->Width - 1, pictureBox1->Height - 1);
	//ImageオブジェクトのGraphicsオブジェクトを作成する
	Graphics^ g = Graphics::FromImage(canvas);

	//Penオブジェクトの作成(幅3黒色)
	Pen^ p = gcnew Pen(System::Drawing::Color::Black, 3);

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			//入力する数値
			String^ drawString = (j + (colN * i)).ToString();
			//行と列からキー作成
			std::string key = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(coordinateString(i, j)).ToPointer();
			//値をstd::stringに直す
			std::string value = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(drawString).ToPointer();
			//メンバに保持する
			(*valueMap)[key] = value;

			//Fontを作成
			System::Drawing::Font^ fnt = gcnew System::Drawing::Font("ＭＳ ゴシック", 12);
			//文字列を表示する範囲を指定する
			RectangleF^ rect = gcnew RectangleF(j * rectWidth, i * rectHigh, rectWidth, rectHigh);
			//セルごとにタテの線を作成する
			g->DrawLine(p, Point(j *rectWidth, i * rectHigh), Point(j * rectWidth, (i + 1) * rectHigh));

			//rectの四角を描く
			g->FillRectangle(Brushes::White, *rect);
			//文字を書く
			g->DrawString(drawString, fnt, Brushes::Black, *rect);
		}
		
		//行ごとに行の線を描画
		g->DrawLine(p, Point(0,(i + 1) * rectHigh), Point(colN * rectWidth, (i + 1) * rectHigh));
	}

	//PictureBox1に表示する
	pictureBox1->Image = canvas;
	pictureBox1->Visible = true;

	this->ResumeLayout(false);
	this->PerformLayout();
}


private: System::Void ButtonBindRelease_Click(System::Object^  sender, System::EventArgs^  e) {
	
	int nowX = this->AutoScrollPosition.X;
	int nowY = this->AutoScrollPosition.Y;

	//マウスクリックされた座標を取得
	int x = ((MouseEventArgs^)e)->X;
	int y = ((MouseEventArgs^)e)->Y;

	//取得した座標からどの行どの列かを取得
	int selectedColN = x / rectWidth;
	int selectedRowN = y / rectHigh;

	//入力するためのフォーム作成
	InputForm^ iForm = gcnew InputForm();

	//キーを作成
	String^ temp = coordinateString(selectedRowN, selectedColN);

	//キーの文字列をstd::stringに変換
	std::string key = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	
	//キーの位置の情報をフォームに渡す
	iForm->value = gcnew String((*valueMap)[key].c_str());

	iForm->ShowDialog();
	

	//フォームに入力された値を取得
	String^ drawString = iForm->value;

	//取得した値をstd::stringに直す
	std::string value = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(drawString).ToPointer();
	//直した値を保管
	(*valueMap)[key] = value;


	//描画オブジェクトを表示元のpictureBoxから作成
	Graphics^ g = Graphics::FromImage(pictureBox1->Image);
	//上から書くための四角形を作成
	RectangleF^ rect = gcnew RectangleF(selectedColN * rectWidth, selectedRowN * rectHigh, rectWidth - 1, rectHigh-1);
	//フォントを作成
	System::Drawing::Font^ fnt = gcnew System::Drawing::Font("ＭＳ ゴシック", 12);
	//rectの四角を描く
	g->FillRectangle(Brushes::White, *rect);
	//取得した値の文字列を四角形に書く
	g->DrawString(drawString, fnt, Brushes::Black, *rect);
	
	//フォームを表示したためトップに戻ってしまうのでイベント発生直後の位置に戻す
	this->AutoScrollPosition = Point(nowX, -nowY);
	//再描画を明示する
	pictureBox1->Invalidate();

	
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//値を保管するマップのインスタンス生成
	valueMap = new std::map<std::string, std::string>();
}

private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	delete valueMap;
}

private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

}
};
}
