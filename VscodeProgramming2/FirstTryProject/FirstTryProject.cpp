#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int main()
{
int a=0;
stack <int> steck;
char str[80];
cin.getline(str,80);
for (int i = 0; i < strlen(str); i++) {
/*if ((str[i] == '(') || (steck.empty()))
cout « "Parentheses aren't balanced";*/
if (str[i] == '(')
steck.push(a);
if (str[i] == ')')
steck.pop();
}
if (steck.empty())
cout<< "Parentheses are balanced";
else
cout<< "Parentheses aren't balanced";
return 0;
}
