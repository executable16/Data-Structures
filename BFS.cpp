#include<bits/stdc++.h>
using namespace std;
bool vis[202];

unordered_map<int,vector<int>> m;
queue<int> Q;
void BFS(int i)
{
	Q.push(i);
	vis[i]=true;
	while(!Q.empty())
	{
		auto y = Q.front();
		cout<<y<<" ";
		Q.pop();
		for(auto x = m[y].begin();x!=m[y].end();x++)
		{
			if(!vis[*x])
			{
				Q.push(*x);
				vis[*x]=true;
			}
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=7;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	BFS(1);
}
