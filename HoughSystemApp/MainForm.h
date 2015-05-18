#pragma once
#include "CannyAlg.h"

namespace HoughSystemApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  systemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zamknijToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  algorytmyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cannyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bigMatrixToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->systemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->algorytmyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cannyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bigMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->systemToolStripMenuItem, 
				this->algorytmyToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(930, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// systemToolStripMenuItem
			// 
			this->systemToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->zamknijToolStripMenuItem});
			this->systemToolStripMenuItem->Name = L"systemToolStripMenuItem";
			this->systemToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->systemToolStripMenuItem->Text = L"System";
			// 
			// zamknijToolStripMenuItem
			// 
			this->zamknijToolStripMenuItem->Name = L"zamknijToolStripMenuItem";
			this->zamknijToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->zamknijToolStripMenuItem->Text = L"Zamknij";
			this->zamknijToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::zamknijToolStripMenuItem_Click);
			// 
			// algorytmyToolStripMenuItem
			// 
			this->algorytmyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->cannyToolStripMenuItem, 
				this->bigMatrixToolStripMenuItem});
			this->algorytmyToolStripMenuItem->Name = L"algorytmyToolStripMenuItem";
			this->algorytmyToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->algorytmyToolStripMenuItem->Text = L"Algorytmy";
			// 
			// cannyToolStripMenuItem
			// 
			this->cannyToolStripMenuItem->Name = L"cannyToolStripMenuItem";
			this->cannyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cannyToolStripMenuItem->Text = L"Canny";
			this->cannyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cannyToolStripMenuItem_Click);
			// 
			// bigMatrixToolStripMenuItem
			// 
			this->bigMatrixToolStripMenuItem->Name = L"bigMatrixToolStripMenuItem";
			this->bigMatrixToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->bigMatrixToolStripMenuItem->Text = L"Big Matrix";
			this->bigMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::bigMatrixToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(930, 511);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Hough Transform System";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void zamknijToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void cannyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 CannyAlg canny;
				 canny.setSource("C:\\Users\\marcin.olejniczak\\Pictures\\zwierzaki\\deer_1.jpg");
				 canny.CannyThreshold(0, 0);
			 }
private: System::Void bigMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::string nazwa_okna = "Matrix"; 
			 cv::namedWindow(nazwa_okna, WINDOW_NORMAL);
			 cv::Mat m(70000, 10000, CV_8UC1);
			 m.setTo(cv::Scalar(5, 10, 15));
			 cv::Vec3b color = m.at<cv::Vec3b>(cv::Point(100,100));
			 color[2] = 255; color[1] = 255; color[0] = 255;
			 m.at<cv::Vec3b>(cv::Point(100,100)) = color;
			 cv::imshow(nazwa_okna, m);
		 }
};
}
