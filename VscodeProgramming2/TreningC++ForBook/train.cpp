#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(vector<int>& nums, int num) {
    int first = 0;
    int last = nums.size() - 1;
    int count = 0;
    while(first<=last){
        int medium = (first+last)/2;
        if(nums[medium] == num) return medium;
        if(nums[medium]<num){
            first = medium+1;
        }else{
            last = medium - 1;
        }
        count++;
    }    
    return first;  
}
void plusOne(vector<int>& digits) {
        bool needToEncrease = true;
        for(int i = digits.size()-1;i >= 0 and needToEncrease; i--)
        {
            if(needToEncrease) digits[i]++;
            if(digits[i]>9){
                if(i-1 < 0){
                    digits.insert(digits.begin(), 1);
                    digits[i+1]=0;
                }else{
                    digits[i]=0;
                    needToEncrease = true;
                }
            }else{
                needToEncrease = false;
            }
        }
        return;
    }
int main(){
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> math;
    vector<pair<int,int>> physics;
    for(int i = 0; i < n; i++){
        int amount, time;
        char object;
        cin >> time >> amount >> object;
        if(object == 'M') math.push_back({amount, time});
        else physics.push_back({amount, time});
    }
    sort(physics.begin(), physics.end(), [] (pair<int, int> a, pair<int, int> b) { return a.second < b.second;});
    sort(math.begin(), math.end(), [] (pair<int, int> a, pair<int, int> b) { return a.second < b.second;});
    int tasks_Ph = 0, tasks_M = 0;
    int tmp;
    for(auto task : physics){
        tmp = t / task.second;
        t -= min(task.first, tmp) * task.second;
        tasks_Ph += min(task.first, tmp);
        if(t <= 0){
            cout << tasks_Ph << " " << tasks_M << endl;
            return 0;
        }
    }
    for(auto task : math){
        tmp = t / task.second;
        t -= min(task.first, tmp) * task.second;
        tasks_M += min(task.first, tmp);
        if(t <= 0){
            cout << tasks_Ph << " " << tasks_M << endl;
            return 0;
        }
    }
    cout << tasks_Ph << " " << tasks_M << endl;
    return 0;
}