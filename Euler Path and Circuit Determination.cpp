#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> m;
bool vis[100005];
void dfs(int u)
{
	vis[u]=true;
	for(auto x : m[u])
	{
		if(!vis[x])
			dfs(x);
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	int count=0,c=0;
	for(int i=1;i<=e;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	for(int i=1;i<=v;i++)
	{
		if(!vis[i])
		{
			count++;
			dfs(i);
			
		}
	}
	
	for(auto x : m)
	{
		if(x.second.size()%2==1)
			c++;
	}
	if(c==0 && count<2)
		cout<<"A circuit and a path\n";
	if(c==2 && count<2)
		cout<<"A Path \n";
	else if(c!=0 && c!=2 || count>1)
		cout<<"Neither a path nor a circuit\n";

}
