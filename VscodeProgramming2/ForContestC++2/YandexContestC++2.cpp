#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map <int,int> test;
    int n1, n2;
    cin >> n1;
    n2 = n1;
    int count = 0;
    while(n1){
        if(n1 & 1) count++;
        n1 >>= 1;
    }
    cout << n2 + count;
    
    return 0;
}