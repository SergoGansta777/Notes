#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
int i, j, count = 0;
int test[5] = {9,1,5,7,10};
for (i = 0; i < 5; i++) {
cout << test[i]<< " ";
}
cout << endl;
int size = 5; //здесь у тебя будет кол-во элементов, который будет подсчитан при чтении из файла
for(int i = 0; i<size;i++)
{
    for(int j = i+1;j<size;j++)
    {
        if(test[j]<test[j-1]){
            count++;
        }else{
            break;
        }
    }
}
cout << count;
return 0;
}