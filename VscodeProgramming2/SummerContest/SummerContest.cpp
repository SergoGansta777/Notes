#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        long long factorial = 1;
        for(int j = 3; j <= 2 * tmp;j++)
        {
            factorial *= j;
        }
        cout << factorial % 1000000007 << endl;
    }
}