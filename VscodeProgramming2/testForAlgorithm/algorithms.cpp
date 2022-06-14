#include <iostream>
#include <vector>

using namespace std;
int BinSearch(vector<int>& arr, int target){
    int first = 0;
    int last = arr.size() - 1;
    while(first <= last){
        int medium = (first + last) / 2;
        if(arr[medium] == target) return medium;
        if(arr[medium] > target){
            last = medium - 1;
        }else{
            first = medium + 1;
        }
    }
    return first;
}

void BiggestSequience(vector<int>& test){
    vector<int> dp = {test[0]};
    vector<int> prev ;
    int j = 0;
    for(int i = 1; i < test.size();i++)
    {
        if(test[i] <= dp[j]){
            int in = BinSearch(dp, test[i]);
            dp[in] = test[i];

        }else{
            dp.push_back(test[i]);
            j++;
        }
    }
    cout << dp.size() << endl;
    for(auto num : dp){
        cout << num << " ";
    }
    cout << endl;
    return ;
}

int main()
{
    int amount, el;
    cin >> amount;
    vector<int> input;
    for(int i = 0; i< amount;i++)
    {
        cin >> el;
        input.push_back(el);
    }
    BiggestSequience(input);
}