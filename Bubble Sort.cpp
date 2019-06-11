#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	bool vis = true;
	for(int i=0;i<n-1;i++)
	{
		vis = false;
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
				swap(a[i],a[j]),vis=true;
		}
		if(!vis)
			break;
	}
	for(auto x : a)
		cout<<x<<" ";
}
