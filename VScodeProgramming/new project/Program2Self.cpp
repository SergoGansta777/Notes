#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream inf("input.txt");
    if(!inf)
    {
        cout << "Входной файл не удается открыть\n";
        return 1;
    }
    char* n2 = new char[10];
    inf.getline(n2,10,'\n');
    int n = atoi(n2);
    int count =0;
    double min = 1000000;
    char** list1 = new char*[n];
    double* value = new double[n];
    for(int i=0;i<n;i++)
    {
        list1[i] = new char[100];
        inf.getline(list1[i],100, '\n');
        cout << list1[i] << endl;
    }
        inf.close();
    for(int i = 0;i<n;i++)
    {
        int countofSpace = 0;
        double process = 0;
        for(int j = 0;list1[i][j]!='\0';j++)
        {
            if(list1[i][j]==' ') countofSpace++;
            if(countofSpace>=2 && list1[i][j]!=' '){
                process += int(list1[i][j]-'0');
            }
        }
        value[i] = process/3;
        if(min>value[i]) min = value[i];
    }
    for(int i =0;i<n;i++)
    {
        if(value[i]==min) count++;
    }

    ofstream out1("output.txt");
    if(!out1)
    {
        cout << "Выходной файл не удается открыть\n";
        return 1;
    }
    if(count > 1) out1 << count << endl;
    for (int i = 0;i<n;i++)
    {
        if(value[i]==min){
            for(int j = 0;char(list1[i][j])!=' ';j++)
            {
                out1 << char(list1[i][j]);
            }
            out1 << endl;
        }
    }
    
    out1.close();
    return 0;
}

