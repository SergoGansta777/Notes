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

vector<vector<int> > adj;
bool visited[4];

void dfs(int s)
{
	if(visited[s]) return;
	visited[s] = true;
	cout << s;
	for(auto u: adj[s])
	{
		dfs(u);
	}
}

int main()
{
	queue<int> q;
	for(int i =0;i<4;i++)
	{
		visited[i]=false;
	}
	int N,M;
	cin >> N >> M;
	adj = vector<vector<int> > (N, vector<int>(N,0));
		for(int i =0;i<M;i++)
		{
			
			int num,j;
			cin >> j >> num;
			j--;
			num--;
			adj[j][i] = num;
			adj[num][i]=j;
			// adj[j].push_back(num);
			// adj[num].push_back(j);
		}
		dfs(1);
}