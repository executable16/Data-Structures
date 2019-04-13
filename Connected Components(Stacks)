#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
unordered_map<int,vector<int>> m;
void DFS(int i)
{
	stack<int> s;
	s.push(i);
	vis[i]=true;
	while(!s.empty())
	{
		auto curr=s.top();
		s.pop();
		for(auto x=m[curr].begin();x!=m[curr].end();x++)
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
	memset(vis,false,sizeof(vis));
	int count=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{	int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	int x;
	
	for(int i=1;i<=n;i++)
		if(!vis[i])
			{	
			  DFS(i);
			  count++;
			}
	cout<<count<<endl;
}
