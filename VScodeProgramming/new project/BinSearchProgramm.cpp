#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int BinSearch(int array[], int index)
{
    int first = 0;
    int last = index;
    int middle = 0;
    int element = array[index];
    while (first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == element) {
            return middle;
        }
        else if (array[middle] < element)
        {
            first = middle+1 ;
        }
        else if (array[middle] > element)
        {
            last = middle-1;
        }     
    }
    return first;
}
int main()
{
    setlocale(LC_ALL, "Russian");
	int arr[12]; 
    int index;
    srand((unsigned) time(NULL));
	for (int i = 0; i < 12; i++)
	{
		arr[i] = rand() % 42 - 21;
		cout << arr[i] << " ";
	}
    cout << endl << "Массив заполнен " << endl;
    for (int i = 1; i < 12; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            int number = arr[i];
            index = BinSearch(arr, (i));
            for (int j = i; j > 0 && arr[j - 1] >= number; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[index] = number;
        }
    }
    cout << "Отсортированный массив: " << endl;
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}