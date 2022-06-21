#include <bits/stdc++.h>

using namespace std;
map<char, int> RomanToArab{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};
int RtA(string s)
{
    int maxIn = 0, maxDig=-1;
    for(int i = 0; i < s.length();i++ ){
        short digit = RomanToArab[s[i]];
        if(digit > maxDig){
            maxIn = i;
            maxDig = digit;
        }
    }
    int result = RomanToArab[s[maxIn]];
    if(maxIn > 0){
        for(int i = maxIn-1; i>=0;i--)
        {
            result-=RomanToArab[s[i]];
        }
    }
    if (maxIn+1 < s.length()){
        for(int i = maxIn + 1; i < s.length();i++){
            bool is_exist = false;
            for(int j = i+1;j< s.length();j++)
            {
                if (RomanToArab[s[j]]> RomanToArab[s[i]]) is_exist = true;
            }
            if(!is_exist){
                result += RomanToArab[s[i]];
            }else{
                result -= RomanToArab[s[i]];
            }
        }
    }
    return result;
}

    bool isValid(string s) {
        stack<char> brackets;
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                brackets.push(s[i]);
            }
            if(s[i] == ')' or s[i] == ']' or s[i] == '}'){
                if(brackets.empty() or char(s[i]-1) != brackets.top() and char(s[i]-2) != brackets.top()) return false;
                if(char(s[i]-1) == brackets.top() or char(s[i]-2) == brackets.top()) brackets.pop();
            }
        }
        return brackets.empty();
    }
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  void FillListNode(ListNode* list)
  {
    ListNode* current = list;
    while(current->next){
        current = current->next;
    }
    int val;
    cin >> val;
    ListNode* node = new ListNode{val} ;
    current->next = node;
    return;
  }
    class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 or !list2) return (!list1)? list2: list1;
       if(list2->val < list1->val){
            ListNode* tmp = list1;
            list1 = list2;
            list2 = tmp;
       }
       ListNode* current1 = list1;
       ListNode* current2 = list2;
       if(current1->next){
        while(current1 and current2){
        if(current1->val <= current2->val and (current1->next)->val >= current2->val){
            ListNode* tmp1 = current1->next;
            ListNode* tmp2 = current2->next;
            current1->next = current2;
            current1 = current1->next;
            current1->next = tmp1;
            current2 = tmp2;
       }else{
        
        current1 = current1->next;
       }
       }
    }else{
        if (!current1->next){
            ListNode* tmp = current1->next;
            current1->next = current2;
            current1 = current1->next;
            current1->next = tmp;
        }
    }
    return list1;
       }

        ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* tmp = head;
        int last_value = head->val;
        bool need_delete = false;
        
        while(current){
            
            if(current->val != last_value){
                if(need_delete){
                    tmp->next = current;
                }
                last_value = current->val;
                tmp = current;
                current= current->next;
            }else{
                if(current == head){
                    current = current->next;
                    continue;
                }
                need_delete = true;
                ListNode* tmp2 = current;
                current = current->next;
                if(tmp2->next){
                    tmp->next = nullptr;
                    break;
                }else{
                    tmp2->next = nullptr;
                }
            }
        }
        return head;
    }
};
void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        return;
    }
     int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0, sum_of_subarr, count = 0;
        for(int i = 0;i < arr.size();i++)
        {
            sum_of_subarr = 0;
            count = 0;
            for(int j = i; j < arr.size();j++){
                count++;
                sum_of_subarr+= arr[j];
               if(count % 2 != 0)
               {
                   sum+=sum_of_subarr;
               }
                
            }
        }
        return sum;
    }
     int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        unordered_map<char,int> hashmap;
        int first =0, result = 0, dublicate_in;
        for(int end = 0; end < s.length(); end++)
        {
            if(hashmap.find(s[end]) != hashmap.end()){
                result = max(result, end - first);
                dublicate_in = hashmap[s[end]];
                for(int i = first; i <= dublicate_in;i++)
                {
                    hashmap.erase(s[i]);
                }
                first = dublicate_in+1;
            }
            hashmap.insert({s[end], end});
        }
        return result;
    }
int main()
{
    // ListNode list1{1};
    // ListNode list2{1};    
    // for(int i = 0;i < count;i++)
    // {
    //     FillListNode(&list1);
    // }
    // for(int i = 0;i < count+2;i++)
    // {
    //     FillListNode(&list2);
    // }
    vector<int> test1 = {4,1, 2};
    vector<int> test2 = {1,4,2,5,3};
    lengthOfLongestSubstring("au");
    return 0;
}