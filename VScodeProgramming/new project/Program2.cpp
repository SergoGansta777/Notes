#include <iostream>

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

int main()
{
    int N,M, lastIn=-1, in, sum, isExist=false, count;
    cout << "Введите длину последовательности: ";
    cin >> N;
    cout << "Введите искомое число: ";
    cin >> M;
    cout << "Заполнение последовательности: " << endl;
    int array[N];
    int helparr[N];
    // for(int i = 0; i < N;i++)
    // {
    //     helparr[i]=-1;
    // }
    for(int i = 0; i < N;i++)
    {
        cin >> array[i];
    }
    cout << "Сортировка..." << endl;
    sortInsert(array, N);
    for(int item : array){
        cout << item << " ";
    }
    cout << endl << "Поиск множества..." << endl;
    for(int i = 0 ; i < N && isExist == false; i++)
    {
        count = 1;
        in=0;
        sum=array[i];
        helparr[in]=array[i];
        in++;
        //Если условие допускает тот случай, когда один элемент = M.
        if(sum==M) 
        {
            isExist = true;
            break;
        }
        
        for(int j = i+1;j < N ;j++)
        {
            if(array[j]>M) break;
            sum+=array[j];
            if(sum>M) break;
            helparr[in] = array[j];
            count++;

            if(sum==M){
                
                isExist = true;
                break;
            }
              in++;
            
        }
    }


    // //
    if(isExist==false)
    {
        cout << "Такого множества не существует";
    }else{
        cout << "Искомое множество: { ";
        for(int i = 0; i<count;i++)
        {
           // if(helparr[i]==-1) break;
            cout << helparr[i] << " ";
        }
        cout << "} - что в сумме равно " << M << endl;
    }
}