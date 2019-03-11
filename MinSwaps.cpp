// Minimum swaps to sort an array in increasing order


#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> x , pair<int,int> y)
{
	return x.first<y.first;
}
int main()
{
	int n;
	cin>>n;
	pair<int,int> a[n];
	bool vis[n]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].second==i || vis[i])
			continue;
		int cycle=0;
		int j=i;
		while(!vis[j])
		{
			vis[j]=1;
			j=a[j].second;
			cycle++;
			//cout<<"cycle "<<cycle<<endl;
		}
		if(cycle)
			ans+=(cycle-1);
	}
	cout<<ans<<endl;
}
