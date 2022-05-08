#include <iostream>
#include<string.h>
#include <math.h>
#include <fstream>

using namespace std;

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
static string GetName(char** member, int n, int index)
{
    setlocale(LC_ALL, "Russian");
    string result = "";
    int count =0;
    for(int i = 0;i<strlen(member[index]);i++)
    {
        if(member[index][i]==' ') count++;
        if(count==2){
            //result[i]='\0';
            break;
        }
        result += char(member[index][i]);
    }
    return result;
}
static bool CheckLess25(int* values,int n, int place1=-1, int place2=-1, int place3=-1)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(values[i]==place1 || values[i]==place2 || values[i]==place3 ) count++;
    }
    if(double(count)/n*100>25) return false;
    return true;
}
static int GetPriseValue(int* values,int size, int exceptnum = -1, int exceptnum2 = -1)
{
    int max = -2000000;
    for(int i = 0;i<size;i++)
    {
        if(max<values[i] && values[i]!=exceptnum && values[i]!=exceptnum2) max = values[i];
    }
    return max;
}
static void GetNumericValueOfMembers(char** str,int* ValueOfMember,int n)
{
    for(int i =0;i<n;i++)
    {
        int tmp = 1;
        ValueOfMember[i]=0;
       for(int j = strlen(str[i])-1;str[i][j]!=' ';j--)
       {
            ValueOfMember[i]+=int(str[i][j]-'0')*tmp;
            tmp*=10; 
       }
    }
    return ;
}
static void Number48()
{
    
    int n;
    cin >> n;
    ifstream inf("listOfMembers.txt");
    if(!inf)
    {
        cout << "Входной файл не удается открыть\n";
        return ;
    }
    char** list1 = new char*[50];
    for(int i=0;i<50;i++)
    {
        list1[i] = new char[100];
        inf.getline(list1[i],100, '\n');
    }
    inf.close();
    Sort(list1,n);

    int* valueOfmembers= new int[n];
    GetNumericValueOfMembers(list1,valueOfmembers,n);
    int Place1stValue = GetPriseValue(valueOfmembers,n);
    int Place2stValue = GetPriseValue(valueOfmembers,n,Place1stValue);
    int Place3stValue = GetPriseValue(valueOfmembers,n,Place1stValue,Place2stValue);

    ofstream out1("resultText.txt");
    if(!out1)
    {
        cout << "Выходной файл не удается открыть\n";
        return ;
    }
    if(CheckLess25(valueOfmembers,n,Place1stValue,Place2stValue,Place3stValue))
    {
        setlocale(LC_ALL, "Russian");
        out1 << "1-st place:" << endl;
        for(int i =0;i<n;i++)
        {
            if(valueOfmembers[i]==Place1stValue) out1 << GetName(list1,n,i) << endl;
        }
        out1 << "2-nd place:" << endl;
        for(int i =0;i<n;i++)
        {
            if(valueOfmembers[i]==Place2stValue) out1 << GetName(list1,n,i) << endl;
        }
        out1 << "3-rd place:" << endl;
        for(int i =0;i<n;i++)
        {
            if(valueOfmembers[i]==Place3stValue) out1 << GetName(list1,n,i) << endl;
        }
    }else{
         bool isExist = false;
         out1 << "Winners:" << endl;
         for(int i = 0;i<n;i++)
         {
             if(valueOfmembers[i]>=400) 
             {
                 out1 << GetName(list1,n,i) << endl;
                 isExist = true;
             }
         }
         if(!isExist) out1 << "none" << endl;
    }
    
    out1.close();
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Number48();
    return 0;
}
//20,48