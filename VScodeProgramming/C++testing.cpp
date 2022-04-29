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
    in.getline(str,1000,'\0');
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
static void Number20()
{
    ifstream in("testingC++FilereadingFutures.txt");
    if(!in)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    char* str = new char[1000];
    in.getline(str,1000,'\0');
    in.close();
    
    ofstream out1("resultText.txt");
    if(!out1)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    for(int i = 0; str[i]!='\0';i++)
    {
        int number1=0,number2=0;
        if((str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/') && i!=0 && str[i+1]!='\0')
        {
            int tmp = 1;
            for(int j=i-1;str[j]!=' ' && j>=0;j--)
            {
                number1+=int(str[j]-'0')*tmp;
                tmp*=10;
                
            }
            tmp=1;
            for(int j = i+1;str[j]!=' ' && str[j]!='\n';j++)
            {
                number2+=int(str[j]-'0');
                if(str[j+1]!=' ' && str[j+1]!='\0' ) number2*=10;
            }
            switch(str[i])
            {
                case('+'):
                out1 << number1+number2<<" ";
                break;
                case('-'):
                out1 << number1-number2<<" ";
                break;
                case('*'):
                out1 << number1*number2<<" ";
                break;
                case('/'):
                out1 << number1/(double)number2<<" ";
                break;
            }
            
        }
       
    }
     out1.close();
    return;
    
    
}
int main()
{
    Number20();
    return 0;
}
//20,48