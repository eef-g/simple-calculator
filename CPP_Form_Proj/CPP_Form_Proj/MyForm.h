#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <msclr\marshal_cppstd.h>
#pragma once

namespace CPPFormProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int chosen_opp = -1; // 0 = add, 1 = sub, 2 = mult, 3 = div
		std::vector<int>* num_list;
		std::stack<double>* num_stack;
	   std::stack<char>* opp_stack;
		
		MyForm(void)
		{
			InitializeComponent();
			resultButton->Select();
			
			calcBox->Text = "";
			num_list = new std::vector<int>();
			num_stack = new std::stack<double>();
			opp_stack = new std::stack<char>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete num_list;
				delete num_stack;
				delete opp_stack;
			}
		}

	private: System::Windows::Forms::Button^ subButton;
	private: System::Windows::Forms::Button^ multButton;
	private: System::Windows::Forms::Button^ divButton;
	private: System::Windows::Forms::Button^ delButton;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::RichTextBox^ calcBox;
	private: System::Windows::Forms::RichTextBox^ historyBox;
	private: System::Windows::Forms::Button^ twoButton;
	private: System::Windows::Forms::Button^ oneButton;
	private: System::Windows::Forms::Button^ threeButton;
	private: System::Windows::Forms::Button^ fourButton;
	private: System::Windows::Forms::Button^ fiveButton;
	private: System::Windows::Forms::Button^ sixButton;
	private: System::Windows::Forms::Button^ sevenButton;
	private: System::Windows::Forms::Button^ eightButton;
	private: System::Windows::Forms::Button^ nineButton;
	private: System::Windows::Forms::Button^ fracButton;
	private: System::Windows::Forms::Button^ powButton;
	private: System::Windows::Forms::Button^ sqrtButton;
	private: System::Windows::Forms::Button^ percentButton;
	private: System::Windows::Forms::Button^ fullClearButton;
	private: System::Windows::Forms::Button^ textClearButton;
	private: System::Windows::Forms::Button^ decimalButton;
	private: System::Windows::Forms::Button^ zeroButton;
	private: System::Windows::Forms::Button^ negateButton;
	private: System::Windows::Forms::Button^ resultButton;
	private: System::Windows::Forms::Label^ label1;
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
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->calcBox = (gcnew System::Windows::Forms::RichTextBox());
			this->historyBox = (gcnew System::Windows::Forms::RichTextBox());
			this->resultButton = (gcnew System::Windows::Forms::Button());
			this->subButton = (gcnew System::Windows::Forms::Button());
			this->multButton = (gcnew System::Windows::Forms::Button());
			this->divButton = (gcnew System::Windows::Forms::Button());
			this->delButton = (gcnew System::Windows::Forms::Button());
			this->twoButton = (gcnew System::Windows::Forms::Button());
			this->oneButton = (gcnew System::Windows::Forms::Button());
			this->threeButton = (gcnew System::Windows::Forms::Button());
			this->fourButton = (gcnew System::Windows::Forms::Button());
			this->fiveButton = (gcnew System::Windows::Forms::Button());
			this->sixButton = (gcnew System::Windows::Forms::Button());
			this->sevenButton = (gcnew System::Windows::Forms::Button());
			this->eightButton = (gcnew System::Windows::Forms::Button());
			this->nineButton = (gcnew System::Windows::Forms::Button());
			this->fracButton = (gcnew System::Windows::Forms::Button());
			this->powButton = (gcnew System::Windows::Forms::Button());
			this->sqrtButton = (gcnew System::Windows::Forms::Button());
			this->percentButton = (gcnew System::Windows::Forms::Button());
			this->fullClearButton = (gcnew System::Windows::Forms::Button());
			this->textClearButton = (gcnew System::Windows::Forms::Button());
			this->decimalButton = (gcnew System::Windows::Forms::Button());
			this->zeroButton = (gcnew System::Windows::Forms::Button());
			this->negateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// addButton
			// 
			this->addButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(291, 362);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(87, 45);
			this->addButton->TabIndex = 0;
			this->addButton->Text = L"+";
			this->addButton->UseVisualStyleBackColor = false;
			this->addButton->Click += gcnew System::EventHandler(this, &MyForm::addButton_Click);
			// 
			// calcBox
			// 
			this->calcBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->calcBox->Location = System::Drawing::Point(12, 35);
			this->calcBox->Multiline = false;
			this->calcBox->Name = L"calcBox";
			this->calcBox->ReadOnly = true;
			this->calcBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->calcBox->Size = System::Drawing::Size(366, 73);
			this->calcBox->TabIndex = 1;
			this->calcBox->Text = L"<INPUT NUMBER HERE>";
			// 
			// historyBox
			// 
			this->historyBox->Location = System::Drawing::Point(384, 61);
			this->historyBox->Name = L"historyBox";
			this->historyBox->ReadOnly = true;
			this->historyBox->Size = System::Drawing::Size(238, 421);
			this->historyBox->TabIndex = 2;
			this->historyBox->Text = L"";
			// 
			// resultButton
			// 
			this->resultButton->BackColor = System::Drawing::Color::LightBlue;
			this->resultButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultButton->Location = System::Drawing::Point(291, 427);
			this->resultButton->Name = L"resultButton";
			this->resultButton->Size = System::Drawing::Size(87, 45);
			this->resultButton->TabIndex = 3;
			this->resultButton->Text = L"=";
			this->resultButton->UseVisualStyleBackColor = false;
			this->resultButton->Click += gcnew System::EventHandler(this, &MyForm::resultButton_Click);
			// 
			// subButton
			// 
			this->subButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->subButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->subButton->Location = System::Drawing::Point(291, 302);
			this->subButton->Name = L"subButton";
			this->subButton->Size = System::Drawing::Size(87, 45);
			this->subButton->TabIndex = 4;
			this->subButton->Text = L"-";
			this->subButton->UseVisualStyleBackColor = false;
			this->subButton->Click += gcnew System::EventHandler(this, &MyForm::subButton_Click);
			// 
			// multButton
			// 
			this->multButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->multButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->multButton->Location = System::Drawing::Point(291, 242);
			this->multButton->Name = L"multButton";
			this->multButton->Size = System::Drawing::Size(87, 45);
			this->multButton->TabIndex = 5;
			this->multButton->Text = L"x";
			this->multButton->UseVisualStyleBackColor = false;
			this->multButton->Click += gcnew System::EventHandler(this, &MyForm::multButton_Click);
			// 
			// divButton
			// 
			this->divButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->divButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->divButton->Location = System::Drawing::Point(291, 182);
			this->divButton->Name = L"divButton";
			this->divButton->Size = System::Drawing::Size(87, 45);
			this->divButton->TabIndex = 6;
			this->divButton->Text = L"÷";
			this->divButton->UseVisualStyleBackColor = false;
			this->divButton->Click += gcnew System::EventHandler(this, &MyForm::divButton_Click);
			// 
			// delButton
			// 
			this->delButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->delButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delButton->Location = System::Drawing::Point(291, 122);
			this->delButton->Name = L"delButton";
			this->delButton->Size = System::Drawing::Size(87, 45);
			this->delButton->TabIndex = 7;
			this->delButton->Text = L"DEL";
			this->delButton->UseVisualStyleBackColor = false;
			this->delButton->Click += gcnew System::EventHandler(this, &MyForm::delButton_Click);
			// 
			// twoButton
			// 
			this->twoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->twoButton->Location = System::Drawing::Point(105, 362);
			this->twoButton->Name = L"twoButton";
			this->twoButton->Size = System::Drawing::Size(87, 45);
			this->twoButton->TabIndex = 8;
			this->twoButton->Text = L"2";
			this->twoButton->UseVisualStyleBackColor = true;
			this->twoButton->Click += gcnew System::EventHandler(this, &MyForm::twoButton_Click);
			// 
			// oneButton
			// 
			this->oneButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oneButton->Location = System::Drawing::Point(12, 362);
			this->oneButton->Name = L"oneButton";
			this->oneButton->Size = System::Drawing::Size(87, 45);
			this->oneButton->TabIndex = 9;
			this->oneButton->Text = L"1";
			this->oneButton->UseVisualStyleBackColor = true;
			this->oneButton->Click += gcnew System::EventHandler(this, &MyForm::oneButton_Click);
			// 
			// threeButton
			// 
			this->threeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->threeButton->Location = System::Drawing::Point(198, 362);
			this->threeButton->Name = L"threeButton";
			this->threeButton->Size = System::Drawing::Size(87, 45);
			this->threeButton->TabIndex = 10;
			this->threeButton->Text = L"3";
			this->threeButton->UseVisualStyleBackColor = true;
			this->threeButton->Click += gcnew System::EventHandler(this, &MyForm::threeButton_Click);
			// 
			// fourButton
			// 
			this->fourButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fourButton->Location = System::Drawing::Point(12, 302);
			this->fourButton->Name = L"fourButton";
			this->fourButton->Size = System::Drawing::Size(87, 45);
			this->fourButton->TabIndex = 11;
			this->fourButton->Text = L"4";
			this->fourButton->UseVisualStyleBackColor = true;
			this->fourButton->Click += gcnew System::EventHandler(this, &MyForm::fourButton_Click);
			// 
			// fiveButton
			// 
			this->fiveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fiveButton->Location = System::Drawing::Point(105, 302);
			this->fiveButton->Name = L"fiveButton";
			this->fiveButton->Size = System::Drawing::Size(87, 45);
			this->fiveButton->TabIndex = 12;
			this->fiveButton->Text = L"5";
			this->fiveButton->UseVisualStyleBackColor = true;
			this->fiveButton->Click += gcnew System::EventHandler(this, &MyForm::fiveButton_Click);
			// 
			// sixButton
			// 
			this->sixButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sixButton->Location = System::Drawing::Point(198, 302);
			this->sixButton->Name = L"sixButton";
			this->sixButton->Size = System::Drawing::Size(87, 45);
			this->sixButton->TabIndex = 13;
			this->sixButton->Text = L"6";
			this->sixButton->UseVisualStyleBackColor = true;
			this->sixButton->Click += gcnew System::EventHandler(this, &MyForm::sixButton_Click);
			// 
			// sevenButton
			// 
			this->sevenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sevenButton->Location = System::Drawing::Point(12, 242);
			this->sevenButton->Name = L"sevenButton";
			this->sevenButton->Size = System::Drawing::Size(87, 45);
			this->sevenButton->TabIndex = 14;
			this->sevenButton->Text = L"7";
			this->sevenButton->UseVisualStyleBackColor = true;
			this->sevenButton->Click += gcnew System::EventHandler(this, &MyForm::sevenButton_Click);
			// 
			// eightButton
			// 
			this->eightButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eightButton->Location = System::Drawing::Point(105, 242);
			this->eightButton->Name = L"eightButton";
			this->eightButton->Size = System::Drawing::Size(87, 45);
			this->eightButton->TabIndex = 15;
			this->eightButton->Text = L"8";
			this->eightButton->UseVisualStyleBackColor = true;
			this->eightButton->Click += gcnew System::EventHandler(this, &MyForm::eightButton_Click);
			// 
			// nineButton
			// 
			this->nineButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nineButton->Location = System::Drawing::Point(198, 242);
			this->nineButton->Name = L"nineButton";
			this->nineButton->Size = System::Drawing::Size(87, 45);
			this->nineButton->TabIndex = 16;
			this->nineButton->Text = L"9";
			this->nineButton->UseVisualStyleBackColor = true;
			this->nineButton->Click += gcnew System::EventHandler(this, &MyForm::nineButton_Click);
			// 
			// fracButton
			// 
			this->fracButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->fracButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fracButton->Location = System::Drawing::Point(12, 182);
			this->fracButton->Name = L"fracButton";
			this->fracButton->Size = System::Drawing::Size(87, 45);
			this->fracButton->TabIndex = 17;
			this->fracButton->Text = L"1/x";
			this->fracButton->UseVisualStyleBackColor = false;
			this->fracButton->Click += gcnew System::EventHandler(this, &MyForm::fracButton_Click);
			// 
			// powButton
			// 
			this->powButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->powButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->powButton->Location = System::Drawing::Point(105, 182);
			this->powButton->Name = L"powButton";
			this->powButton->Size = System::Drawing::Size(87, 45);
			this->powButton->TabIndex = 18;
			this->powButton->Text = L"pow";
			this->powButton->UseVisualStyleBackColor = false;
			this->powButton->Click += gcnew System::EventHandler(this, &MyForm::powButton_Click);
			// 
			// sqrtButton
			// 
			this->sqrtButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->sqrtButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sqrtButton->Location = System::Drawing::Point(198, 182);
			this->sqrtButton->Name = L"sqrtButton";
			this->sqrtButton->Size = System::Drawing::Size(87, 45);
			this->sqrtButton->TabIndex = 19;
			this->sqrtButton->Text = L"sqrt";
			this->sqrtButton->UseVisualStyleBackColor = false;
			this->sqrtButton->Click += gcnew System::EventHandler(this, &MyForm::sqrtButton_Click);
			// 
			// percentButton
			// 
			this->percentButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->percentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percentButton->Location = System::Drawing::Point(12, 122);
			this->percentButton->Name = L"percentButton";
			this->percentButton->Size = System::Drawing::Size(87, 45);
			this->percentButton->TabIndex = 20;
			this->percentButton->Text = L"%";
			this->percentButton->UseVisualStyleBackColor = false;
			// 
			// fullClearButton
			// 
			this->fullClearButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->fullClearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fullClearButton->Location = System::Drawing::Point(105, 122);
			this->fullClearButton->Name = L"fullClearButton";
			this->fullClearButton->Size = System::Drawing::Size(87, 45);
			this->fullClearButton->TabIndex = 21;
			this->fullClearButton->Text = L"CE";
			this->fullClearButton->UseVisualStyleBackColor = false;
			this->fullClearButton->Click += gcnew System::EventHandler(this, &MyForm::fullClearButton_Click);
			// 
			// textClearButton
			// 
			this->textClearButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->textClearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textClearButton->Location = System::Drawing::Point(198, 122);
			this->textClearButton->Name = L"textClearButton";
			this->textClearButton->Size = System::Drawing::Size(87, 45);
			this->textClearButton->TabIndex = 22;
			this->textClearButton->Text = L"C";
			this->textClearButton->UseVisualStyleBackColor = false;
			this->textClearButton->Click += gcnew System::EventHandler(this, &MyForm::textClearButton_Click);
			// 
			// decimalButton
			// 
			this->decimalButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->decimalButton->Location = System::Drawing::Point(198, 427);
			this->decimalButton->Name = L"decimalButton";
			this->decimalButton->Size = System::Drawing::Size(87, 45);
			this->decimalButton->TabIndex = 23;
			this->decimalButton->Text = L".";
			this->decimalButton->UseVisualStyleBackColor = true;
			this->decimalButton->Click += gcnew System::EventHandler(this, &MyForm::decimalButton_Click);
			// 
			// zeroButton
			// 
			this->zeroButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zeroButton->Location = System::Drawing::Point(105, 427);
			this->zeroButton->Name = L"zeroButton";
			this->zeroButton->Size = System::Drawing::Size(87, 45);
			this->zeroButton->TabIndex = 24;
			this->zeroButton->Text = L"0";
			this->zeroButton->UseVisualStyleBackColor = true;
			this->zeroButton->Click += gcnew System::EventHandler(this, &MyForm::zeroButton_Click);
			// 
			// negateButton
			// 
			this->negateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->negateButton->Location = System::Drawing::Point(12, 427);
			this->negateButton->Name = L"negateButton";
			this->negateButton->Size = System::Drawing::Size(87, 45);
			this->negateButton->TabIndex = 25;
			this->negateButton->Text = L"+/-";
			this->negateButton->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30));
			this->label1->Location = System::Drawing::Point(414, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 58);
			this->label1->TabIndex = 26;
			this->label1->Text = L"History";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(623, 484);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->negateButton);
			this->Controls->Add(this->zeroButton);
			this->Controls->Add(this->decimalButton);
			this->Controls->Add(this->textClearButton);
			this->Controls->Add(this->fullClearButton);
			this->Controls->Add(this->percentButton);
			this->Controls->Add(this->sqrtButton);
			this->Controls->Add(this->powButton);
			this->Controls->Add(this->fracButton);
			this->Controls->Add(this->nineButton);
			this->Controls->Add(this->eightButton);
			this->Controls->Add(this->sevenButton);
			this->Controls->Add(this->sixButton);
			this->Controls->Add(this->fiveButton);
			this->Controls->Add(this->fourButton);
			this->Controls->Add(this->threeButton);
			this->Controls->Add(this->oneButton);
			this->Controls->Add(this->twoButton);
			this->Controls->Add(this->delButton);
			this->Controls->Add(this->divButton);
			this->Controls->Add(this->multButton);
			this->Controls->Add(this->subButton);
			this->Controls->Add(this->resultButton);
			this->Controls->Add(this->historyBox);
			this->Controls->Add(this->calcBox);
			this->Controls->Add(this->addButton);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Simple Calc";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// FORM FUNCTIONS

	// MANUAL CLICKING INPUT
	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('+');
	}

	private: System::Void resultButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(calcBox->Text))
		{
			return;
		}
		num_stack->push(System::Convert::ToDouble(calcBox->Text));
		RunCalculation();
	}

	private: System::Void subButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('-');
	}
	
	private: System::Void multButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('*');
	}

	private: System::Void divButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('/');
	}
    private: System::Void decimalButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText(".");
    }
	private: System::Void textClearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		calcBox->Text = "";
	}

	private: System::Void fullClearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearCalculator();
	}


	private: System::Void fracButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('f');
		UpdateTotal('f');
		calcBox->Text = System::Convert::ToString(num_stack->top());
		num_stack->pop();
		opp_stack->pop();
	}

	private: System::Void powButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('p');
	}

	private: System::Void sqrtButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputIntake('s');
		UpdateTotal('s');
		calcBox->Text = System::Convert::ToString(num_stack->top());
		num_stack->pop();
		opp_stack->pop();
	}

	private: System::Void delButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DelChar();
	}
	private: System::Void zeroButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("0");
	}
	private: System::Void oneButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("1");
	}
	private: System::Void twoButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("2");
	}
	private: System::Void threeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("3");
	}
	private: System::Void fourButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("4");
	}
	private: System::Void fiveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("5");
	}
	private: System::Void sixButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("6");
	}
	private: System::Void sevenButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("7");
	}
	private: System::Void eightButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("8");
	}
	private: System::Void nineButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AddText("9");
	}


	// KEYBOARD INPUT
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == System::Convert::ToChar(Keys::Enter))
		{
			if (String::IsNullOrEmpty(calcBox->Text))
			{
				return;
			}
			num_stack->push(System::Convert::ToDouble(calcBox->Text));

			RunCalculation();
		}
		switch (e->KeyChar)
		{
		case '0':
			calcBox->Text += "0";
			break;
		case '1':
			calcBox->Text += "1";
			break;
		case '2':
			calcBox->Text += "2";
			break;
		case '3':
			calcBox->Text += "3";
			break;
		case '4':
			calcBox->Text += "4";
			break;
		case '5':
			calcBox->Text += "5";
			break;
		case '6':
			calcBox->Text += "6";
			break;
		case '7':
			calcBox->Text += "7";
			break;
		case '8':
			calcBox->Text += "8";
			break;
		case '9':
			calcBox->Text += "9";
			break;
		case '+':
			InputIntake('+');
			break;
		case '*':
			InputIntake('*');
			break;
		case '/':
			InputIntake('/');
			break;
		case '=':
			if (String::IsNullOrEmpty(calcBox->Text))
			{
				return;
			}
			num_stack->push(System::Convert::ToDouble(calcBox->Text));
			RunCalculation();
		case '-':
			InputIntake('-');
			break;
		case 'c':
			ClearCalculator();
		default:
			System::Console::WriteLine("Invalid Key Pressed.");
			break;
		}
	}


	// CUSTOM FUNCTIONS

	private: System::Void InputIntake(char operation) {
		if (String::IsNullOrEmpty(calcBox->Text))
		{
			return;
		}
		num_stack->push(System::Convert::ToDouble(calcBox->Text));
		opp_stack->push(operation);
		calcBox->Text = "";
	}

	private: System::Void DelChar() {
		std::string cpp_calcBox_text = msclr::interop::marshal_as<std::string>(calcBox->Text);

		if (cpp_calcBox_text != "")
		{
			cpp_calcBox_text.pop_back();
		}
		String^ out = gcnew String(cpp_calcBox_text.c_str());
		calcBox->Text = out;
	}

	private: System::Void UpdateTotal(char operation){
		double output = 0;
		double num_a, num_b;
		int num_stack_size = num_stack->size();
		int opp_stack_size = opp_stack->size();
		if ( (num_stack->size() >= 1) && (opp_stack->size() >= 1) )
		{
			switch (operation)
			{
			case '+':
				num_b = num_stack->top();
				num_stack->pop();
				num_a = num_stack->top();
				num_stack->pop();
				output = num_a + num_b;
				break;
			case '-':
				num_b = num_stack->top();
				num_stack->pop();
				num_a = num_stack->top();
				num_stack->pop();
				output = num_a - num_b;
				break;
			case '*':
				num_b = num_stack->top();
				num_stack->pop();
				num_a = num_stack->top();
				num_stack->pop();
				output = num_a * num_b;
				break;
			case '/':
				num_b = num_stack->top();
				num_stack->pop();
				num_a = num_stack->top();
				num_stack->pop();
				output = num_a / num_b;
				break;
			case 'p':
				num_b = num_stack->top();
				num_stack->pop();
				num_a = num_stack->top();
				num_stack->pop();
				output = pow(num_a, num_b);
				break;
			case 's':
				num_a = num_stack->top();
				num_stack->pop();
				output = sqrt(num_a);
				break;
			case 'f':
				num_a = num_stack->top();
				num_stack->pop();
				output = 1 / num_a;
				break;
			default:
				break;
			}
			num_stack->push(output);
		}
	}

	private: System::Void RunCalculation(){

		double result = 0;
		char opperation = 'h';
		while (!opp_stack->empty())
		{
			opperation = opp_stack->top();
			UpdateTotal(opperation);
			opp_stack->pop();
		}
		result = num_stack->top();
		num_stack->pop();
		calcBox->Text = System::Convert::ToString(result);
	}


	private: System::Void ClearCalculator() {
		while (!num_stack->empty())
		{
			num_stack->pop();
		}
		while (!opp_stack->empty())
		{
			opp_stack->pop();
		}
		calcBox->Text = "";
	}

	private: System::Void AddText(std::string txt) {
		std::string curr_text = msclr::interop::marshal_as<std::string>(calcBox->Text);
		curr_text += txt;
		String^ out_string = gcnew String(curr_text.c_str());
		calcBox->Text = out_string;
	}

};
}
