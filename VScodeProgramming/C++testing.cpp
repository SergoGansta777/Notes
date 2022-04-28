#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

static void Example1()
{
    int a,b;
    ifstream in("testingC++FilereadingFutures.txt");
    if(!in)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    in >> a >> b;
    ofstream out1("result.txt");
    if(!out1)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    out1 << a+b;

    in.close();
}
static void Example2()
{
    ifstream in("text.txt");
    if(!in)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }

    char* str = new char[1000];
    //in.ignore();
    in.getline(str,1000,'\n');
    cout << str;
    in.close();
    ofstream out1("resultText.txt");
    if(!out1)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    for(int i = 0;str[i]!='\0';i++)
    {
         if(str[i]!=' ') {
             out1 << str[i];
             cout << str[i];
         }
    } 
    out1.close();
    return;
}
int main()
{
    Example2();
        return 0;
}