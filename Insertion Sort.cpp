#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		{
			int j=i;
			while(j>0 && a[j-1]>a[j])
				swap(a[j-1],a[j]),j--;
		}
	for(auto x : a)
		cout<<x<<" ";
}
