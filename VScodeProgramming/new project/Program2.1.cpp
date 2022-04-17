#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <string.h>

using namespace std;

void bsort(int* start, int* end)
{
	for (int i = 0; i < (end - start) - 1; ++i)
		for (int* j = start; j < end - 1; j++)
		{
			if (*j > *(j + 1))
			{
				int buf = *j;
				*j = *(j + 1);
				*(j + 1) = buf;
			}
		}
}

void csort(int* start, int* end, int d)
{
	int* temp = new int[d + 1]{};
	for (int* i = start; i < end; i++)
	{
		temp[*i]++;
	}
	int elem = 0;
	for (int *i = temp; i < temp + d + 1; i++)
	{
		for (int j = 0; j < *i; j++)
		{
			start[elem] = i - temp;
			++elem;
		}
	}
	delete[] temp;
}
int Pow(int num, int y) {
	int result=1;
	for(int i = 0; i < y; i++)
	{
		result*=num;
	}
	return result;
}
float Pow(float num, int y) {
	float result=1;
	for(int i = 0; i < y; i++)
	{
		result*=num;
	}
	return result;
}
char* Pow(char* str, int y)
{
	setlocale(LC_ALL, "Russian");
	int size = strlen(str)*y;
	char* result = new char[size];
	int index = 0;
	for(int i = 0; i<strlen(str);i++)
	{
		for(int j = 0; j < y; j++)
		{
			*(result+index) = *(str+i);
			index++; 
		}
	}
	return result;
}


int main(void)
{
	setlocale(LC_ALL, "Russian");
	unsigned int y;
	cout << "Введите положительную степень y" << endl;
	cin >> y;
	int number;
	float num;
	char* str = new char[1000];
	cin >> number;
	cin >> num;
	cout << "Введите строку: " << endl;
	cin.ignore();
	cin.getline(str, '.');
	cout << Pow(number, y) << endl;
	cout << Pow(num,y) << endl;
	char* result = Pow(str, y);
	cout << result << endl;
	return 0;
}