#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N,M, Sum=0;
    cin >> N;
    int array[N];
    cin >> M;
    for(int i = 1; i<=N;i++)
    {
        cin >> array[i];
    }
    int maxvariants = pow(N,2);
    for(int i = 1; i<maxvariants;i++)
    {
        int temp = i, Sum=0;
        for(int j = 1;j<=N;j++)
        {
            if(temp & 1)
            {
                Sum+=array[j];
            }
            temp>>1;
        }
        if(Sum==M)
        {
            cout << "{ ";
           for(int j = 1;j<=N;j++)
            {
                if(temp & 1)
                {
                    cout << array[j] << ", ";
                }
                temp>>1;
            }
            cout << "}" ;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}