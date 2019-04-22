#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long maxi = INT_MIN, best = INT_MIN;
	for(int i=0;i<n;i++)
	{
		maxi = max(a[i],maxi+a[i]);
		best = max(best,maxi);
	}
	cout<<best<<endl;
}
