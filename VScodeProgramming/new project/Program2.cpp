#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

//Задание 23
using namespace std;

class test{
    class ExamensOfStudents{
	public:
	int numberInGroup;
	string LastName;
	int numberOfStudentBook;
	int grade;
	
};
private:
vector<test::ExamensOfStudents> listOfStudents;
public:
static void FindStudentByFirsLetters()
{
	cout << "Введите фамилию студента или ее часть: " << endl;
	string tmp;
	cin >> tmp;
	cout << "\nРезультаты поиска:\n";
	bool isNotFound = true;
	for(auto student : listOfStudents)
	{
		bool isFound = true;
		for(int i = 0; i<tmp.size();i++)
		{
			if(tmp[i]!=student.LastName[i] && (tmp[i]!=char(int(student.LastName[i]) + 32) && char(int(tmp[i])+32)!=student.LastName[i])){
				isFound=false;
				break;
			}
		}
		if(isFound) {
			cout <<"- " << student.LastName << " - студент группы " << student.numberOfStudentBook << " с оценкой за экзамен " << student.grade << endl;
			isNotFound = false;
		}
	}
	if(isNotFound) cout << "...\nСоответствий запросу не найдено.\n";

	return;
}
static void test::SortByLastName(){
	sort(listOfStudents.begin(), listOfStudents.end(), [](ExamensOfStudents a, ExamensOfStudents b) {
  	return a.LastName < b.LastName;
	});
}
static void SortByNumberInGroup(){
	sort(listOfStudents.begin(), listOfStudents.end(), [](ExamensOfStudents a, ExamensOfStudents b) {
  	return a.numberInGroup < b.numberInGroup;
	});
}
static void GetPercentOfStudentWithGrade()
{
	cout << "Введите искомую оценку: ";
	int grade; cin >> grade;
	cout << "Студенты, получившие за экзмен оценку " << grade << ", занимают около ";
	int count=0;
	for(auto student : listOfStudents)
	{
		if(student.grade==grade)
		{
			count++;
		}
	}
	double percent = double(count)/listOfStudents.size();
	cout << percent*100 << " процентов от общего числа студентов (всего " << listOfStudents.size() <<")\n";
}
static void PrintAllListInFile()
{
	ofstream file("PrintedStudents.txt");
	for(auto student : listOfStudents){
		file << student.numberInGroup << "; " << student.LastName << "; " << student.numberOfStudentBook << "; " << student.grade << ";\n";
	}
	return;
}
static void EnterNewStudent(){
	ExamensOfStudents student;
	cout << "Введите данный студента через пробел в следующем формате: номер в группе, фамилия, номер зачетки, оценка за экзамен:\n";
	cin >> student.numberInGroup >> student.LastName >> student.numberOfStudentBook >> student.grade;
	cout << "Запись данных студента завершена." << endl;
	listOfStudents.push_back(student);
	cout << "";
	return;
}
static void EnterNewGroup(){
	ifstream inf("listOfStudents.txt");
    if(!inf)
    {
        cout << "Не удается открыть список студентов\n";
        return;
    }
	int i=0;
	while(!inf.eof()){
		string tmp;
		getline(inf,tmp,';');

		if(tmp=="") break;
		ExamensOfStudents infoAboutStudent;
		listOfStudents.push_back(infoAboutStudent);
		
		listOfStudents[i].numberInGroup = stoi(tmp);
		inf.ignore();

		getline(inf,tmp,';');
		inf.ignore();

		listOfStudents[i].LastName = tmp;
		inf.ignore();

		getline(inf,tmp,';');
		listOfStudents[i].numberOfStudentBook = stoi(tmp);
		inf.ignore();

		getline(inf,tmp,';');
		listOfStudents[i].grade = stoi(tmp);
		inf.ignore();
		i++;
	}
	return;
}
}
int main() {
    char opt, waitEnter;
	do{
		cout << "\n--------------------------------------------------------------\n";
		cout << "Выберите действие и введите соответствующую цифру:\n";
		cout << " 1 - Считать данные о группе студентов из файла\n";
		cout << " 2 - Добавить данные одного студента с клавиатуры\n";
		cout << " 3 - Получить процент студентов с определённой оценкой\n";
		cout << " 4 - Отсортировать список студентов по номеру в группе\n";
		cout << " 5 - Отсортировать список студентов по фамилиям\n";
		cout << " 6 - Сохранить список студентов и их данные в файл\n";
		cout << " 7 - Найти данные студента по фамилии\n";
		cout << "\nВведите '-' для завершения работы программы(без кавычек)\n";
		cin >> opt;
		cout << "\n--------------------------------------------------------------\n";
		switch(opt){
			case '1':
			EnterNewGroup();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '2':
			EnterNewStudent();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '3':
			GetPercentOfStudentWithGrade();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '4':
			SortByNumberInGroup();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '5':
			SortByLastName();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '6':
			PrintAllListInFile();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
			case '7':
			FindStudentByFirsLetters();
			cout << "Введите любой символ: ";
			cin >> waitEnter;
			break;
		}
	}while(opt!='-');
    return 0;

}


//23
//cin.tie(0)
//cout.tie(0)
//ios_base::sync_with_stdio(false)