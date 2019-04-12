/* Learing resource : https://cp-algorithms.com/graph/topological-sort.html */


#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> m;
vector<int> s;
bool vis[15];
void dfs(int u)
{
	vis[u]=true;
	for(auto x : m[u])
	{
		if(!vis[x])
		dfs(x);
	}
	s.push_back(u);
}
int main()
{
	int V,E;
	cin>>V>>E;
	for(int i=1;i<=V;i++)
	{
		vis[i]=false;
	}
	for(int i=1;i<=E;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
	}
	for(int i=1;i<=V;i++)
		if(!vis[i])
			dfs(i);
	reverse(s.begin(),s.end());
	for(auto x : s)
		cout<<x<<" ";
}
