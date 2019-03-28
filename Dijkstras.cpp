#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<pair<int,int>>> m;
bool vis[10005];
long long int  dis[10005];

void dj(int i)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	dis[1]=0;
	while(!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		int x = curr.first;
		int y = curr.second;
		if(vis[y])
			continue;
		vis[y]=true;
		for(auto t : m[y])
		{
			if(dis[y] + t.first < dis[t.second])
			{
				dis[t.second] = dis[y] + t.first;
				pq.push({dis[t.second],t.second});
			}
		}

	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	int V,E;
	cin>>V>>E;
	for(int i=1;i<=V;i++)
	{
		dis[i]=(int)INFINITY;
	}
	for(int i=1;i<=E;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		m[a].push_back({w,b});
	}
	dj(1); // here 1 is the source vertex
	for(int i=2;i<=V;i++)
		cout<<dis[i]<<" ";
}
