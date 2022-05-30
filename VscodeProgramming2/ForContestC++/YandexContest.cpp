#include <iostream>
#include <cstring>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;
 
 int NOD(int num1, int num2){
     while(num1!=0 && num2!=0){
         if(num1>num2){
             num1%=num2;
         }else{
             num2%=num1;
         }
     }
     return num1+num2;
 }
 bool IsPrime(int N)
{
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
            return false;
    if (N < 2)
        return false;
    return true;
}
int main()
{
    int m,n;
    cin >> m >> n;
    bool isExist = false;
    for(int i = m;i<=n;i++)
    {
        if(i!=2&&i&2==0) continue;
        if(IsPrime(i)){
            cout << i << endl;
            if(!isExist)isExist=true;
        }
    }
    if(!isExist) cout << "Absent" << endl;
    return 0;
}