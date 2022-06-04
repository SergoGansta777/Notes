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
    int TomX,TomY, JerryX, JerryY, N , x , y;
    cin >> JerryX >> JerryY;
    cin >> TomX >> TomY;
    cin >> N;
    int count = 0;
    for(int i = 0; i<N;i++)
    {
        cin >> x >> y;
        if(pow(JerryX-x,2)+pow(JerryY-y,2) < 2*(pow(TomX-x,2)+pow(TomY-y,2)) && count==0){
         count = i+1;   
        }
    }
    if(count!=0){
        cout << count << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;

}