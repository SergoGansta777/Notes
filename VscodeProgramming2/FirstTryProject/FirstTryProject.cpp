#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc>1){
        cout << argv[1] << endl;
        cout << "Получилось" << endl;
    }
	int A, B, count;
	cin >> A >> B;
	int lastDecent = A/10, help;
	for(int i = A; i<=B;i++)
    {
        if(i==-100 || i==0){
                cout << i << " ";
                lastDecent = (i+1)/10;
                continue;
            }
        if((lastDecent != i/10 && i%10!=0 ) || i==1){
            lastDecent = i/10;
            if(i!=A+1) cout << endl;
        }
        cout << i ;
        if(i%10!=0) cout << " ";
    }
    cout << endl;
	return 0;
}