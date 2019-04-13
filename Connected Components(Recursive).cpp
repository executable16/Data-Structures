#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
unordered_map<int,vector<int>> m;
void dfs(int u)
{
	vis[u]=true;
	for(auto x : m[u])
	{
		if(!vis[x])
		{
			dfs(x);
		}
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			count++,dfs(i);
	}
	cout<<count<<endl;
}
