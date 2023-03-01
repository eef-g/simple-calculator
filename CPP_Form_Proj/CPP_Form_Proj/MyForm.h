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
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ resultButton;
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
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->resultButton = (gcnew System::Windows::Forms::Button());
			this->subButton = (gcnew System::Windows::Forms::Button());
			this->multButton = (gcnew System::Windows::Forms::Button());
			this->divButton = (gcnew System::Windows::Forms::Button());
			this->delButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// addButton
			// 
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(373, 362);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(87, 45);
			this->addButton->TabIndex = 0;
			this->addButton->Text = L"+";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MyForm::addButton_Click);
			// 
			// calcBox
			// 
			this->calcBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->calcBox->Location = System::Drawing::Point(12, 12);
			this->calcBox->Multiline = false;
			this->calcBox->Name = L"calcBox";
			this->calcBox->ReadOnly = true;
			this->calcBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->calcBox->Size = System::Drawing::Size(448, 90);
			this->calcBox->TabIndex = 1;
			this->calcBox->Text = L"<INPUT NUMBER HERE>";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(466, 61);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(269, 421);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// resultButton
			// 
			this->resultButton->BackColor = System::Drawing::Color::LightBlue;
			this->resultButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultButton->Location = System::Drawing::Point(373, 422);
			this->resultButton->Name = L"resultButton";
			this->resultButton->Size = System::Drawing::Size(87, 45);
			this->resultButton->TabIndex = 3;
			this->resultButton->Text = L"=";
			this->resultButton->UseVisualStyleBackColor = false;
			this->resultButton->Click += gcnew System::EventHandler(this, &MyForm::resultButton_Click);
			// 
			// subButton
			// 
			this->subButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->subButton->Location = System::Drawing::Point(373, 302);
			this->subButton->Name = L"subButton";
			this->subButton->Size = System::Drawing::Size(87, 45);
			this->subButton->TabIndex = 4;
			this->subButton->Text = L"-";
			this->subButton->UseVisualStyleBackColor = true;
			this->subButton->Click += gcnew System::EventHandler(this, &MyForm::subButton_Click);
			// 
			// multButton
			// 
			this->multButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->multButton->Location = System::Drawing::Point(373, 242);
			this->multButton->Name = L"multButton";
			this->multButton->Size = System::Drawing::Size(87, 45);
			this->multButton->TabIndex = 5;
			this->multButton->Text = L"x";
			this->multButton->UseVisualStyleBackColor = true;
			this->multButton->Click += gcnew System::EventHandler(this, &MyForm::multButton_Click);
			// 
			// divButton
			// 
			this->divButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->divButton->Location = System::Drawing::Point(373, 182);
			this->divButton->Name = L"divButton";
			this->divButton->Size = System::Drawing::Size(87, 45);
			this->divButton->TabIndex = 6;
			this->divButton->Text = L"÷";
			this->divButton->UseVisualStyleBackColor = true;
			this->divButton->Click += gcnew System::EventHandler(this, &MyForm::divButton_Click);
			// 
			// delButton
			// 
			this->delButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delButton->Location = System::Drawing::Point(373, 122);
			this->delButton->Name = L"delButton";
			this->delButton->Size = System::Drawing::Size(87, 45);
			this->delButton->TabIndex = 7;
			this->delButton->Text = L"DEL";
			this->delButton->UseVisualStyleBackColor = true;
			this->delButton->Click += gcnew System::EventHandler(this, &MyForm::delButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 484);
			this->Controls->Add(this->delButton);
			this->Controls->Add(this->divButton);
			this->Controls->Add(this->multButton);
			this->Controls->Add(this->subButton);
			this->Controls->Add(this->resultButton);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->calcBox);
			this->Controls->Add(this->addButton);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Simple Calc";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

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

	private: System::Void delButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DelChar();
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
		if ( (num_stack->size() >= 2) && (opp_stack->size() >= 1) )
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
};
}
