#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <cstring> 
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[];


void dfs(int s, bool visited[])
{
	if(visited[s]) return;
	visited[s] = true;
	for(auto u: adj[s])
	{
		dfs(u,visited);
	}
}f

int main()
{
	int N,M;
	cin >> N >> M;
	bool visited[N];
	adj[N];
	for(int i =0;i<4;i++)
	{
		visited[i]=false;
	}

		for(int i =0;i<M;i++)
		{
			
			int num,j;
			cin >> j >> num;
			j--;
			num--;
			// adj[j][i] = num;
			// adj[num][i]=j;
			adj[j].push_back(num);
			adj[num].push_back(j);
		}
		int count = 0;
		for(int i = 0;i<N;i++)
		{
			if(!visited[i]){
				count++;
				dfs(i,visited);
			}
		}
		cout << count << endl;
}