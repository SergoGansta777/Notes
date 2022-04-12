#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N,M, Sum=0;
    cin >> N;
    cin >> M;
    int array[N];
    for(int i = 0; i<N;i++)
    {
        cin >> array[i];
    }
    int maxvariants = pow(2,N);
    for(int i = 1; i<=maxvariants;i++)
    {
        int temp = i, Sum=0;
        for(int j = 1;j<=N;j++)
        {
            if(temp & 1)
            {
                Sum+=array[j-1];
            }
            temp>>=1;
        }
        if(Sum==M)
        {
            cout << "{ ";
            for(int j = 0;j<N;j++)
            {
                if(i & 1)
                {
                    cout << array[j] << " ";
                }
                i>>=1;
            }
            cout << "} - что в сумме равно "<< M << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}