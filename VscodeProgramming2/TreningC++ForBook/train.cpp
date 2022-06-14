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
}
int main(){
    vector<int> test = {1,2,3,0,0,0};
    vector<int> test1 = {2,5,6};
    merge(test, 0, test1, 2);
    return 0;
}