#include <iostream>

using namespace std;

int main()
{
    int N, M, sum=0, lastIn=-1, firstIn;
    bool isExict=true;
    cout << "Введите длину последовательнсти: ";
    cin >> N;
    cout << "Введите исходное число: ";
    cin >> M;
    int arr[N];
    for(int i = 0; i< N; i++)
    {
       cin >>  arr[i];
    }
    for(int i = 0; i < N && isExict==true; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(arr[j]>M) break;
            sum+=arr[j];
            if(sum==M && arr[j] !=M) //Если множество может состоять из одного элемента, то оставить только sum==M 
            {
                lastIn=j;
                firstIn=i;
                isExict=false;
                break;
            }
        }
        sum=0;
    }
    if(lastIn==-1)
    {
        cout << "Такого множества не существует";
    }else{
        cout << "Искомое множество: { ";
        for(int i = firstIn; i<=lastIn;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
    }
}