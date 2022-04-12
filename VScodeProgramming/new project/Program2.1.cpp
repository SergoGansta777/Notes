#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

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

int main(void)
{
	cout << "n: " << endl;
	int n; cin >> n;
	cout << "d: " << endl;
	int d; cin >> d;
	int* arr = new int[n];
	
	for (long long i = 0; i < n; i++)
	{
		arr[i] = rand() % d;

		//output
		/*cout << arr[i] << " ";*/
	}
	cout << endl;

	clock_t start = clock();

	//type function here
	sort(arr,arr+n);

	
	clock_t end = clock();

	//output
	/*for (long long i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;*/

	cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	delete[] arr;
	return 0;
}