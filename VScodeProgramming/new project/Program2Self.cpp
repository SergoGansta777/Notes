#include <iostream>
#include <math.h>

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

void sortInsert(int arr[], int N){
    int index;
    int number;
    for (int i = 1; i < N; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            number = arr[i];
            index = BinSearch(arr, (i));
            for (int j = i; j > 0 && arr[j - 1] >= number; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[index] = number;
        }
    }
}

bool prostoNumer(int n){
    for (int i = 2; i<=sqrt(n); i++) 
        if (n % i == 0) 
            return false;   
    return true; 
}

double Sq(double arg)
{
    return arg*arg;
}
int Sq(int arg)
{
    return arg*arg;
}
int main()
{
    int x = 11;
    double y = 3.1416;
    printf("%d v kvdrate = %d, %f v kvadrate = %f\n",x,Sq(x),y,Sq(y));
}

//14 Вариант
int main1()
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