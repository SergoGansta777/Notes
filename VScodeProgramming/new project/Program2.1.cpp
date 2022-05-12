#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main() {
    int N,M;
	cin >> N >> M;
	multiset<int> hours;
	set<int> defaultHours;
	vector<int> result;
	for(int i = 0; i<M;i++)
	{
		int num;
		cin >> num;
		vector<int> str;
		for(int j = 0; j<num;j++)
		{
			int num2;
			cin >> num2;
			if(find(str.begin(),str.end(),num2)!=str.end()) continue;
			str.push_back(num2);
			hours.insert(num2);
			defaultHours.insert(num2);
		}
	}
	bool isExist = false;
	for(auto item : defaultHours)
	{
		if(hours.count(item) == M){
			result.push_back(item);
			isExist =  true;
		}
	}
	if(isExist){
		sort(result.begin(),result.end());
		for(auto item : result)
		{
			cout << item << " ";
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
    return 0;
}
//cin.tie(0)
//cout.tie(0)
//ios_base::sync_with_stdio(false)