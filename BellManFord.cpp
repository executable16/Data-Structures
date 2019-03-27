#include<bits/stdc++.h>
using namespace std;
struct graph
{

	int start;
	int end;
	int cost;
};
graph v[1000005];
long long int dis[100005];
int main()
{
	int V,E;
	cin>>V>>E;
	//graph v[E];
	//int dis[V+1];
	for(int i=0;i<V+1;i++)
	{
		dis[i]=(int)INFINITY;
	}
	for(int i=1;i<=E;i++)
	{
		cin>>v[i].start;
		cin>>v[i].end;
		cin>>v[i].cost;
	}
	dis[1]=0;
	for(int i=0;i<V-1;i++)
	{
		int f=0;
		for(int j=1;j<=E;j++)
		{
			if(dis[v[j].start] + v[j].cost < dis[v[j].end])
			{
				dis[ v[j].end] = dis[v[j].start] + v[j].cost;
				f=1;
			}
		}
		if(f==0)
			break;
	}
	for(int i=1;i<=V;i++)
	{
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}
