#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int A, B, count;
	cin >> A >> B;
	count = A / 10;
	for (int i = A; i <= B; i++)
	{
		
		cout << i << " ";
		if(i / 10 != count )
		{
			if (i < 0 && i%10!=0) continue;
			cout << endl;
			count = i / 10;
			
		}
		
	}
	return 0;
}