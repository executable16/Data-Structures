#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[10000];
int n;
int calc()
{
	int max_here = 0;
	int max_overall = -INF;
	for(int i=0;i<n;i++)
	{
		max_here=max_here+a[i];
		if(max_overall<max_here)
			max_overall=max_here;
		if(max_here<0)
			max_here=0;
	}
	return max_overall;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<calc()<<endl;
	

}
