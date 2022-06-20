#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, length;
    cin >> n >> length;
    char* word = new char[length];
    char opt;
    int unknown_chars = length;
    cin >> opt;
    for(int i = 0; i < length;i++)
    {
        word[i] = opt;
    }
    string tmp;
    int answer = 0;
    for(int i = 0; i < n;i++)
    {
        
        cin >> tmp;
        for(int j = 0; j < tmp.length() and length > 0;j++)
        {
            if(tmp[j] != opt){
                if(word[j] != opt and word[j] != tmp[j]){
                    answer = -1 * (i+1);
                    length = -1;
                    break;
                }else{
                    word[j] = tmp[j];
                    length--;
                }
            }
            if(length == 0)
            {
                answer = i + 1;
            }
        }
        
    }
    if(length!=0)
    {
        cout << "-" << n-1 <<endl;
    }else{
        cout << answer << endl;
    }

}