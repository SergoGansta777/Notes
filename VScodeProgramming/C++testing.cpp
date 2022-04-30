#include <iostream>
#include<string.h>
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
void Sort(char** strlist, int strcnt)
{
	for(int i = 0; i < strcnt - 1; i++)
    {
        if(strlen(strlist[i])==1) break;
        for(int j = i + 1; j < strcnt; j++)
        {
            if(strlen(strlist[j])==1) break;
            if(strcmp(strlist[i], strlist[j]) > 0) {
				char* tmp = strlist[i];
				strlist[i] = strlist[j];
				strlist[j] = tmp;
			}
        }
			
    }
	return;
}
static void Number48()
{
    int n;
    cin >> n;
    ifstream inf("listOfMembers.txt");
    if(!inf)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    char list [n][100];
    char** list1 = new char*[50];
    for(int i=0;i<50;i++)
    {
        //inf.getline(list[i],999, '\n');
        list1[i] = new char[100];
        inf.getline(list1[i],100, '\n');
    }
    inf.close();
    Sort(list1,n);
    ofstream out1("resultText.txt");
    if(!out1)
    {
        cout << "Файл не удается открыть\n";
        return ;
    }
    for(int i = 0;i<n;i++)
    {
        out1 << list1[i] << endl;
    }
    out1.close();
    return;
}

int main()
{
    Number48();
    return 0;
}
//20,48