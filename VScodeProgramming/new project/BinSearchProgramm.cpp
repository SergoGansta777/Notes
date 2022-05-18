#include <iostream>
#include <fstream>
#include <cstring> 
#include <string>
using namespace std;
char* rus(const char* text)
{
	char* bufRus = new char[20];
	//OemToCharA(text, bufRus);
	return bufRus;
}
struct BD1
{
	int day;
	int month;
	int year;
};
struct contact
{
	char fio[40];
	char number[13];
	BD1 BD;
	char address[150];
};
struct contact Notebook[30];  int k = -1;
ifstream Note; ofstream ToNote;
void NewContact()
{
	ToNote.open("Test.txt", ios::app);
	cout << "--------- Ââîä íîâîãî êîíòàêòà ---------" << endl; k++;
	cout << "ÔÈÎ (÷åðåç ïðîáåë): "; cin.getline(Notebook[k].fio, 40, '\n'); ToNote << Notebook[k].fio << '\n';
	cout << "Íîìåð òåëåôîíà: "; cin >> Notebook[k].number; ToNote << rus(Notebook[k].number) << '\n';
	cout << "Äàòà ðîæäåíèÿ (÷åðåç ïðîáåë äåíü, ìåñÿö, ãîä): "; cin >> Notebook[k].BD.day >> Notebook[k].BD.month >> Notebook[k].BD.year;
	ToNote << Notebook[k].BD.day << '.' << Notebook[k].BD.month << '.' << Notebook[k].BD.year << '\n';
	cout << "Àäðåññ: "; cin.getline(Notebook[k].address, 150); ToNote << rus(Notebook[k].address) << '\n';
	ToNote.close();
}
void ReadingFromNotebook()
{
	char* temp = new char[1000]; Note.open("Test.txt");
    // Note.getline(temp,1000,'\0');
    // cout << temp;
	while (!Note.eof())
	{
		
        string help;
		Note.getline(temp,1000);
        if(temp[0] == '\0') break;
		k++;
       // Notebook[k].fio = help;
		Note.getline(Notebook[k].number, 13);
		//Note.getline(temp, 3, '.'); 
		getline(Note, help,'.');
		Notebook[k].BD.day = stoi(help); //Note.ignore();
		//Note.getline(temp, 3, '.'); 
		getline(Note, help,'.');
		Notebook[k].BD.month = stoi(help); //Note.ignore();
		getline(Note, help);
		int t = stoi(help); //Note.ignore();
		Notebook[k].BD.year = t;
		Note.getline(Notebook[k].address,1000);
        //Note.ignore();
	}
	Note.close();
	return;
}
void ShowNote()
{
	for (int i = 0; i < k; i++)
	{
		cout << Notebook[i].fio << endl;
		cout << Notebook[i].number << endl;
		cout << Notebook[i].BD.day << '.' << Notebook[i].BD.month << '.' << Notebook[i].BD.year << endl;
		cout << Notebook[i].address << endl << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	ReadingFromNotebook(); ShowNote();
	cout << endl << k;
	//NewContact(); //ShowNote(); 
	cout << endl << k;
}