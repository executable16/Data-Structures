#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
unordered_map<int,vector<pair<int,int>>> M;
long long prims(int i)
{
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	long long sum=0;
	pq.push(make_pair(0,i));
	while(!pq.empty())
	{
		auto curr=pq.top();
		pq.pop();
		int x = curr.second;
		int cost = curr.first;
		if(vis[x])
			continue;
		sum+=cost;
		vis[x]=true;

		for(auto t : M[x]) // O( 2*E log(V) )
		{
			if(!vis[t.second])
				pq.push(t);
		}
	}
	return sum;



}
int main()
{
	int n,m;
	memset(vis,false,sizeof(vis)); 
	cin>>n>>m;
	for(int i=0;i<m;i++) // O(E)
	{
		int a,b,w;
		cin>>a>>b>>w;
		M[a].push_back(make_pair(w,b));
		M[b].push_back(make_pair(w,a));
	}
	long long ans=prims(1);
	cout<<ans<<endl;
}
