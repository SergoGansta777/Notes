#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <cstring>

//Задание 23
using namespace std;
int countOfStudent=0;
class ExamensOfStudents{
	public:
	int numberInGroup;
	string LastName;
	int numberOfStudentBook;
	int grade;
	
};
vector<ExamensOfStudents> listOfStudents;
static void EnterNewGroup();
static void EnterNewStudent();
static void PrintAllListInFile();
static void GetPercentOfStudentWithGrade(int grade);
static void SortByNumberInGroup();
static void SortByLastName();
int main() {
    
	EnterNewGroup();
	//EnterNewStudent();
	SortByLastName();
	PrintAllListInFile();
	//GetPercentOfStudentWithGrade();
	string str;

    return 0;

}

static void SortByLastName(){
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
	int count;
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
//23
//cin.tie(0)
//cout.tie(0)
//ios_base::sync_with_stdio(false)