#include"bits/stdc++.h"
using namespace std;
bool vis[100005];
unordered_map<int,vector<int>> m;
void dfs(int i)
{
	stack <int> s;
	s.push(i);
	while(!s.empty())
	{
		auto curr = s.top();
		cout<<curr<<" ";
		vis[curr]=true;
		s.pop();
		for(auto x = m[curr].begin(); x!=m[curr].end(); x++)
		{
			if(!vis[*x])
			{
				s.push(*x);
				vis[*x]=true;
			}	
		}

	}
}
int main()
{
	int V,E;
	cin>>V>>E;
	for(int i=1;i<=E;i++)
	{	
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}

	dfs(1);
}
