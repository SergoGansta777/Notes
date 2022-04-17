#include <iostream>
#include <math.h>

using namespace std;


int* MergeArr(int arr1[], int arr2[], int n1 = 0, int n2 = 0)
{
    int* newArr;
    newArr = new int[n1+n2];
    int i=0,j=0,k=0;
    if(n1==0 && n2 ==0)
    {
        cout << "Ошибка ввода!" << endl;
    }
    while(i<n1 || j < n2)
    {
        if(!(i<n1) && j<n2)
        {
            *(newArr+k)=arr2[j];
            j++;
            k++;
        }else if(i<n1 && !(j<n2))
        {
            *(newArr+k) = arr1[i];
            i++;
            k++;
        }else if(arr1[i]<arr2[j])
        {
            *(newArr+k)=arr1[i];
            i++;
            k++;
        }else{
            *(newArr+k)=arr2[j];
            j++;
            k++;
        }
    }
    return newArr;
}

int main()
{
    int n1,n2;
    cin >> n1;
    int arr[n1];
    for(int i = 0;i<n1;i++)
    {
        cin >> arr[i];
    }
    cin >> n2;
    int arr2[n2];
    for(int i = 0; i<n2;i++)
    {
        cin >> arr2[i];
    }
    int* here = MergeArr(arr,arr2,n1,n2);
    if(n1!=0 && n2!=0) cout << "Итоговый массив " << endl;
    for(int i = 0; i < n1+n2; i++)
    {
        cout << *(here+i) << " ";
    }
    cout << endl;
    return 0;
}