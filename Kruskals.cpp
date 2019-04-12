#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> v;
int ranke[100005];
int parent[100005];
bool comp(pair<int,pair<int,int>> x , pair<int,pair<int,int>> y)
{
	return x.first < y.first;
}
void make_set(int x)
{
	parent[x]=x;
	ranke[x]=0;
}
int find_set(int x)
{
	if(parent[x]==x)
		return x;
	else
		return parent[x]=find_set(parent[x]);
}
void union_set(int x ,int y)
{
	int a = find_set(x);
	int b = find_set(y);
	if(a!=b)
	{
		if(ranke[a]<ranke[b])
			swap(a,b);
		parent[b]=a;
		if(ranke[a]==ranke[b])
			ranke[a]++;
	}
}
long long int kruskals()
{
	long long int mincost=0;
	for(int i=0;i<v.size();i++)
	{
		int x = v[i].second.first;
		int y = v[i].second.second;
		if(find_set(x)!=find_set(y))
		{
			mincost+=v[i].first;
			//cout<<x<<"---> "<<y<<endl;
			union_set(x,y);
		}
	}
	return mincost;
}
int main()
{
	for(int i=1;i<=10;i++)
	{
		make_set(i);
		int a,b,cost;
		cin>>a>>b>>cost;
		v.push_back(make_pair(cost,make_pair(a,b)));
	}
	sort(v.begin(), v.end(),comp);
	long long int ans=kruskals();
	cout<<ans<<endl;
	


}
