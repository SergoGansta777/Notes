#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
	int N, number, div3 = 0, div17 = 0, ifeq = 0, div51 = 0;
	long long comp = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		if (number % 51 == 0)
		{
			div51++;
			ifeq = 1;
			continue;
		}
		if (number % 3 == 0)
		{
			div3++;
		}
		else if (number % 17 == 0)
		{
			div17++;
		}
		ifeq = 0;
	}
	if (ifeq == 1 && N==div51) {
		cout << (N * (N - 1)) / 2 << endl;
	}
	else if (div3 == 1 || div17 == 1)
	{
		cout <<( div3 * div17 +(N-1)* div51) << endl;
	}
	else {
		cout << (((div3 > div17) ? div17 : div3)+(N-1)*div51) << endl;
	}
    return 0;
}