#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    int a,b;
    
    string str;
    char* test = new char[256];
    cin.getline(test,256);

    ifstream in("testingC++FilereadingFutures.txt");
    if(!in)
    {
        cout << "Файл не удается открыть\n";
        return 1;
    }
    in >> a >> b;
    ofstream out1("testingC++FilereadingFutures.txt");
    if(!out1)
    {
        cout << "Файл не удается открыть\n";
        return 1;
    }
    out1 << a+b;
    cout << a+b;
    // getline(in,str);
    // cout << str << endl;
    in.close();
        return 0;
}