#pragma once

#include "Floyd.h"
#include "Danzig.h"
#include "InitZero.h"
#include "HistoryMatrix.h"
#include "WeightMatrixPlus.h"
#include <algorithm>

namespace KursovaRobota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool danz;
	int **ph,
		**pw,
		**coo,	//матриця координат
		**adja,	//початкова матриця ваги
		vertex;	//кількість вершин

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  vertex_num;

	protected: 

	private: System::Windows::Forms::DataGridView^  WeightMatrix;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label4;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  Weight;



	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::NumericUpDown^  U;
	private: System::Windows::Forms::NumericUpDown^  V;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  dButton;

	private: System::Windows::Forms::RadioButton^  fButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  Path;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  Time;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  Iter;
	private: System::Windows::Forms::TextBox^  Oper;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
















	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->vertex_num = (gcnew System::Windows::Forms::NumericUpDown());
			this->WeightMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Weight = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->U = (gcnew System::Windows::Forms::NumericUpDown());
			this->V = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dButton = (gcnew System::Windows::Forms::RadioButton());
			this->fButton = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Path = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Time = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Iter = (gcnew System::Windows::Forms::TextBox());
			this->Oper = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vertex_num))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WeightMatrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->U))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->V))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vertex num";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// vertex_num
			// 
			this->vertex_num->Location = System::Drawing::Point(12, 22);
			this->vertex_num->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->vertex_num->Name = L"vertex_num";
			this->vertex_num->Size = System::Drawing::Size(48, 20);
			this->vertex_num->TabIndex = 1;
			this->vertex_num->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->vertex_num->ValueChanged += gcnew System::EventHandler(this, &Form1::vertex_num_ValueChanged);
			// 
			// WeightMatrix
			// 
			this->WeightMatrix->AllowUserToAddRows = false;
			this->WeightMatrix->AllowUserToDeleteRows = false;
			this->WeightMatrix->AllowUserToResizeColumns = false;
			this->WeightMatrix->AllowUserToResizeRows = false;
			this->WeightMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->WeightMatrix->ColumnHeadersVisible = false;
			this->WeightMatrix->Location = System::Drawing::Point(115, 22);
			this->WeightMatrix->Name = L"WeightMatrix";
			this->WeightMatrix->RowHeadersVisible = false;
			this->WeightMatrix->Size = System::Drawing::Size(203, 187);
			this->WeightMatrix->TabIndex = 2;
			this->WeightMatrix->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::WeightMatrix_CellValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(167, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Weight Matrix";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 276);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Weight from vertex";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(161, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"to";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(225, 276);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"is";
			// 
			// Weight
			// 
			this->Weight->Location = System::Drawing::Point(245, 269);
			this->Weight->Name = L"Weight";
			this->Weight->Size = System::Drawing::Size(34, 20);
			this->Weight->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 44);
			this->button1->TabIndex = 10;
			this->button1->Text = L"WeightAndPath";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// U
			// 
			this->U->Location = System::Drawing::Point(115, 269);
			this->U->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->U->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->U->Name = L"U";
			this->U->Size = System::Drawing::Size(40, 20);
			this->U->TabIndex = 12;
			this->U->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// V
			// 
			this->V->Location = System::Drawing::Point(183, 269);
			this->V->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->V->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->V->Name = L"V";
			this->V->Size = System::Drawing::Size(36, 20);
			this->V->TabIndex = 13;
			this->V->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dButton);
			this->groupBox1->Controls->Add(this->fButton);
			this->groupBox1->Location = System::Drawing::Point(12, 69);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(95, 89);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Algorythm";
			// 
			// dButton
			// 
			this->dButton->AutoSize = true;
			this->dButton->Location = System::Drawing::Point(14, 63);
			this->dButton->Name = L"dButton";
			this->dButton->Size = System::Drawing::Size(58, 17);
			this->dButton->TabIndex = 1;
			this->dButton->TabStop = true;
			this->dButton->Text = L"Danzig";
			this->dButton->UseVisualStyleBackColor = true;
			// 
			// fButton
			// 
			this->fButton->AutoSize = true;
			this->fButton->Location = System::Drawing::Point(14, 31);
			this->fButton->Name = L"fButton";
			this->fButton->Size = System::Drawing::Size(50, 17);
			this->fButton->TabIndex = 0;
			this->fButton->TabStop = true;
			this->fButton->Text = L"Floyd";
			this->fButton->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(473, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(521, 572);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(351, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Build";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(716, 3);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Graph";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 316);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"The Path:";
			// 
			// Path
			// 
			this->Path->Location = System::Drawing::Point(85, 309);
			this->Path->Name = L"Path";
			this->Path->Size = System::Drawing::Size(100, 20);
			this->Path->TabIndex = 19;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(348, 100);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Time:";
			// 
			// Time
			// 
			this->Time->Location = System::Drawing::Point(397, 97);
			this->Time->Name = L"Time";
			this->Time->Size = System::Drawing::Size(29, 20);
			this->Time->TabIndex = 23;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(328, 134);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Iterations:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(322, 171);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Oparatons:";
			// 
			// Iter
			// 
			this->Iter->Location = System::Drawing::Point(397, 131);
			this->Iter->Name = L"Iter";
			this->Iter->Size = System::Drawing::Size(56, 20);
			this->Iter->TabIndex = 26;
			// 
			// Oper
			// 
			this->Oper->Location = System::Drawing::Point(397, 168);
			this->Oper->Name = L"Oper";
			this->Oper->Size = System::Drawing::Size(56, 20);
			this->Oper->TabIndex = 27;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(128, 215);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Filefill";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(228, 215);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Randomfill";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(967, 534);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->Oper);
			this->Controls->Add(this->Iter);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Time);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->Path);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->V);
			this->Controls->Add(this->U);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Weight);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->WeightMatrix);
			this->Controls->Add(this->vertex_num);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"vertex_num";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vertex_num))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WeightMatrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->U))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->V))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void ScanMatrix(int Size, int** p) {//зчитування матриці з граф. інтерфейсу в двовимірний масив **p
			for (int i=0; i<Size; i++)
				for (int j=0; j<Size; j++)
					try
					{
						p[i][j] = Convert::ToInt32(WeightMatrix->Rows[i]->Cells[j]->Value);
					}
			catch (System::FormatException^ exeption){	} //ігнорування при введенні некоректних даних, далі передбачено повідомлення про помилку 
		 }
private: void RandomFill(int v_num) { //рандомне заповнення матриці ваги числами з діапазону від 0 до 10
			 srand(time(NULL));
			 for (int i=0; i<v_num; i++)
				 for (int j=0;j<v_num; j++)
					WeightMatrix->Rows[i]->Cells[j]->Value = rand()%10;
		 }
private: void FileFill(int v_num) {	//зчитування матриці ваги з файлу IN.txt
			FILE *f = fopen("IN.txt", "r");
			char ch_;
			int arr_index = 0;
			bool flag;
			for (int i=0; i<v_num && (!feof(f)); i++)
				for (int j=0; j<v_num && (!feof(f)); j++)
				{
					flag = false;
					char *arr = new char[5];
					ch_ = fgetc(f);
					for (; !feof(f);)
					{
						if (ch_ == 45)
						{
							arr[arr_index++] = fgetc(f)-2;
							ch_ = fgetc(f);
							flag = true;
						}
						else if (48 > ch_ || ch_ > 57)
							break;
						else
						{
							arr[arr_index++] = ch_;
							ch_ = fgetc(f);
							flag = true;
						}
					}
					if (flag == true) 
					{
						WeightMatrix->Rows[i]->Cells[j]->Value = atoi(arr);
						delete []arr;
						arr_index = 0;
					}
					else break;
				}
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {	//встановлення мінімальної розмірності матриці в 2
			WeightMatrix->ColumnCount = 2;
			WeightMatrix->RowCount = 2;
			WeightMatrix->AutoResizeColumns();
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
				
		 }
private: System::Void vertex_num_ValueChanged(System::Object^  sender, System::EventArgs^  e) {	//побудова матриці
			WeightMatrix->ColumnCount = Convert::ToInt32(vertex_num->Value);
			WeightMatrix->RowCount = Convert::ToInt32(vertex_num->Value);
			WeightMatrix->AutoResizeColumns();
		 }
private: System::Void WeightMatrix_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {	//корекція структури матриці
			WeightMatrix->AutoResizeColumns();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	//кнопка 1
			string path;	//зберігає шлях
			char buffer[20];	//буфер
			int num = 0,	//шлях в числовому еквіваленті
				stepin = 1,	//степінь числа десять 
				ten = 1;	//число десять
			int tops_num = Convert::ToInt32(vertex_num->Value);	//зчитування кількості вершин з поля граф. інтер. vertex_num
			pw = new int*[tops_num];	//динамічне створення матриці ваги
			for (int i=0; i<tops_num; i++)
				pw[i] = new int[tops_num];	
			ph = new int*[tops_num];	//int **ph //динамічне створення матриці історії
			for (int i=0; i<tops_num; i++)
				ph[i] = new int[tops_num];
			InitZero(pw, tops_num);
			InitZero(ph, tops_num);
			ScanMatrix(tops_num, pw);
			ScanMatrix(tops_num, ph);
			WeightMatrixPlus(pw, tops_num);
			HistoryMatrix(ph, tops_num);
			danz = false;//мітка чи був обраний метод Данцига
			int* time_;	//для зберігання інфи про час, ітерації, операції
			if (fButton->Checked)	//якщо в граф. інтер. відмічений метод Флойда
			{
				time_ = Floyd(pw, ph, tops_num);
				Time->Text = Convert::ToString(time_[0]);
				Iter->Text = Convert::ToString(time_[1]);
				Oper->Text = Convert::ToString(time_[2]);
				delete []time_;
			}
			else if (dButton->Checked)	//якщо в граф. інтер. відмічений метод Данцига
			{
				time_ = Danzig(pw, tops_num);
				danz = true;
				Time->Text = Convert::ToString(time_[0]);
				Iter->Text = Convert::ToString(time_[1]);
				Oper->Text = Convert::ToString(time_[2]);
				delete []time_;
			}
			int u = Convert::ToInt32(U->Value);	//зчитування початкової вершини шляху
			int v = Convert::ToInt32(V->Value);	//зчитування кінцевої вершини шляху
			if (u > tops_num	//при відсутності шляху або некоректному вводу даних
				|| v > tops_num)
			{
				Weight->Text = Convert::ToString("Error!");	//повідомлення про помилку
				Path->Text = Convert::ToString("Error!");	//повідомлення про помилку
			}
			else if (pw[u-1][v-1] == SHRT_MAX)
			{
				Weight->Text = Convert::ToString("Error!");	//повідомлення про помилку
				Path->Text = Convert::ToString("Error!");	//повідомлення про помилку
			}
			else if (u == v)	//якщо початкова та кінцева вершини збігаються, то шлях буде рівним нулю
			{
				Weight->Text = Convert::ToString(0);
				Path->Text = Convert::ToString(0);
			}
			else 
			{
				int result_ = 0;	//змінна для запису в файл ваги шляху
				result_ = pw[u-1][v-1];	
				Weight->Text = Convert::ToString(pw[u-1][v-1]);	//при коректних вхідних даних виводимо вагу шляху
				if (danz == true)	//якщо ми обрали Данцига, то відновити шлях не вдасться
					Path->Text = Convert::ToString("No for Danzig!");
				else	//якщо Флойд, то можна відновити шлях з використанням матриці історії
				{
					num = u;	//записуємо в шлях початкову вершину
					for (;;)
					{
						if (ph[u-1][v-1] == v)	//умова завершення шляху
						{
							ten = 1;	//оновлення множника
							for (int i=0; i<stepin; i++)	//відновлення множника
								ten *= 10;
							num += (v*ten);	//записуємо в шлях останню вершину помноживши її на відповідне число ten
							break;	//кінець
						}
						else
						{
							ten = 1;	//оновлення множника
							for (int i=0; i<stepin; i++)	//обчислення множника
								ten *= 10;
							stepin++;	//збільшення степені числа десять
							num += (ph[u-1][v-1]*ten);	//записуємо в шлях поточну вершину помноживши її на відповідне число ten
							u = ph[u-1][v-1];	//наступна вершина нашого шляху
						}
					}
					_itoa(num, buffer, 10);	//запис числового варіанту нашого шляху в символьний варіант буферу buffer
					path = buffer;		//запис з буферу до рядка
					reverse(path.begin(), path.end());	//інвертування рядка
					Path->Text = gcnew System::String(path.c_str());	//виведення шляху у відповідне поле граф. інтеру.
				}
				FILE *f = fopen("Result.txt", "w");	//запис у файл результату(ваги)
				char ch_[3];
				_itoa(result_, ch_, 10);
				fputs(ch_, f);
				fclose(f);
			}
			//for(int i=0; i<tops_num; i++)	//видалення пам'яті
			//	delete [] ph[i];
			//for(int i=0; i<tops_num; i++)
			//	delete [] pw[i];
		}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {		//малювання графа(залежність від кнопка 2)
			Pen^ pen = gcnew Pen(Color::Black);	//створення об'єкту перо для малювання кола
			System::Drawing::Font^ fn = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 7.0F, FontStyle::Bold);	//задання шрифта з параметрами виду, розміру та стилю
			Brush^ br;	//створення пензля для малювання символів
			br = Brushes::Green; //зелений пензлик
			String^ s;	//створення системного рядка для малювання символів
			if (adja == NULL){} //при відсутності вхідних даних малюнок відсутній
			else {
			for (int i=0; i<vertex; i++)
				for (int j=0; j<vertex; j++)
					if (adja[i][j] != 0) //якщо шлях є
					{
						s = Convert::ToString(i+1);	//записуємо до нашого рядка номер початкової вершини
						e->Graphics->DrawLine(System::Drawing::Pens::Green, coo[i][0], coo[i][1], coo[j][0], coo[j][1]);	//малюємо відрізок (дві початкові координати, дві кінцеві)
						e->Graphics->DrawString(s, fn, br, coo[i][0], coo[i][1]);	//малюемо рядок з параметрами рядок, шрифт, пензлик та координатами
						s = Convert::ToString(j+1);	//записуємо до нашого рядка номер кінцевої вершини
						e->Graphics->DrawString(s, fn, br, coo[j][0], coo[j][1]);	//малюемо рядок з параметрами рядок, шрифт, пензлик та координатами
						s = Convert::ToString(adja[i][j]);	//записуємо до нашого рядка номер вагу ребра
						e->Graphics->DrawString(s, fn, br, (coo[i][0]+coo[j][0])/2, (coo[i][1]+coo[j][1])/2);	//малюемо рядок з параметрами рядок, шрифт, пензлик та координатами поділеними на 2, оскільки вагу ребра нам потрібно розмістити посередині ребра
						e->Graphics->DrawEllipse(pen, coo[i][0], coo[i][1], 10, 10);	//малюємо два кола
						e->Graphics->DrawEllipse(pen, coo[j][0], coo[j][1], 10, 10);
					}
			}
			if (ph == NULL || danz == true){}
			else {
				int u = Convert::ToInt32(U->Value);
				int v = Convert::ToInt32(V->Value);
				if (u > vertex || v > vertex || u == v){}
				else if (pw[u-1][v-1] == SHRT_MAX) {}
				else {
					int c1;
					for (;;)
						if (ph[u-1][v-1] == v)
						{
							e->Graphics->DrawLine(System::Drawing::Pens::Red, coo[u-1][0], coo[u-1][1], coo[v-1][0], coo[v-1][1]);
							break;
						}
						else			
						{
							c1 = u;
							u = ph[u-1][v-1];
							e->Graphics->DrawLine(System::Drawing::Pens::Red, coo[c1-1][0], coo[c1-1][1], coo[u-1][0], coo[u-1][1]);
						}
				}
			}
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {	//кнопка 2
			srand(time(NULL));
			vertex = Convert::ToInt32(vertex_num->Text);	//зчитування кількості вершин
			coo = new int*[vertex];		//динамічне створення матриці координат
			for (int i=0; i<vertex; i++)
				coo[i] = new int[2];
			for (int i=0; i<vertex; i++)	//ініціалізація матриці координат випадковими координатами
				for (int j=0; j<2; j++)
					coo[i][j] = rand()%500;
			adja = new int*[vertex];	//динамічне створення матриці початкової ваги
			for (int i=0; i<vertex; i++)
				adja[i] = new int[vertex];
			InitZero(adja, vertex);		//ініціалізація матриці початкової ваги нулями
			ScanMatrix(vertex, adja);	//ініціалізація матриці початкової ваги відповідною матрицею зчитаною з граф. інтеру
			pictureBox1->Refresh();	//оновлення малюнку графа
			for(int i=0; i<vertex; i++)	//очищення пам'яті
				delete [] adja[i];
			for(int i=0; i<vertex; i++)
				delete [] coo[i];
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {	//кнопка заповнення матриці з файлу
			 FileFill(Convert::ToInt32(vertex_num->Text));
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {	//кнопка заповнення матриці випадковими числами
			 RandomFill(Convert::ToInt32(vertex_num->Text));
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
