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

int* MergeArr(int arr1[], int arr2[], int n)
{
    int* newArr;
    newArr = new int[n*2];
    int i=0,j=0,k=0;
    while(i<n || j < n)
    {
        if(arr1[i]<((j<n)?arr2[j]:100000))
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
    int n;
    cin >> n;
    int arr[n] = {1,4,7,9,10,13,15};
    int arr2[n] = { 3,4 ,5 ,8 , 9, 10, 11};
    int* here = MergeArr(arr,arr2,n);
    for(int i = 0; i < n*2; i++)
    {
        cout << *(here+i) << " ";
    }

}