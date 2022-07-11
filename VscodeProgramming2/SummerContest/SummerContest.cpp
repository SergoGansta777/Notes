#include <bits/stdc++.h>

using namespace std;

vector<int> z_function_trivial(string s)
{
    int n = (int)s.length();
    vector<int> z(n, 0);
    for(int i =1 ; i< n; i++)
    {
        while(i + z[i] < n and s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
         
    }
    return z;
}

int main()
{   
    string tmp;
    getline(cin , tmp);
    auto test = z_function_trivial(tmp);
    for (auto n : test){
        cout << n << " ";
    }
        
}