#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>

using namespace std;
 
int main()
{
    ifstream fileRead("test.txt");
    string line = ""; 
    getline(fileRead,line);
    int countOfSpace = 0;
    string resultLine="", word1="", word2="";
    for(int i = 0; i< line.size();i++)
    {
        if(line[i]==' ' || line[i]=='\n' || line[i]=='\0')
        {
            countOfSpace++;
            if(countOfSpace%2==0){
                resultLine+=word2;
                resultLine+=" ";
                resultLine+=word1;
                resultLine+=line[i];
                word1="";
                word2="";
                
            }
            continue;
        }
        if((countOfSpace+1)%2!=0)
        {
            word1+=line[i];
        }
        if((countOfSpace+1)%2==0){
            word2+=line[i];
        }  
    }
    resultLine+=(word2=="")?"":(word2+" ");
    resultLine+=(word1=="")?"":word1;
    ofstream answer("output.txt");
    answer << resultLine;
    return 0;
}