#include<bits/stdc++.h>
using namespace std;
const int N =100005;
int segtree[4*N];
void buildTree(int pos,int start,int end,int a[])
{
	if(start>end)
		return;
	if(start==end)
	{
		if(a[start]==0)
			segtree[pos]=1;
		return;
	}
	int mid=start+end>>1;
	buildTree(2*pos+1,start,mid,a);
	buildTree(2*pos+2,mid+1,end,a);
	segtree[pos]=segtree[2*pos+1] + segtree[2*pos+2];
}
int query(int pos,int start,int end,int k)
{
	if(segtree[pos]<k)
		return INT_MAX;
	if(start == end)
		return start;
	int mid=start+end>>1;
	if(segtree[2*pos+1]>=k)
		return query(2*pos+1,start,mid,k);
	else
		return query(2*pos+2,mid+1,end,k-segtree[2*pos+1]);

}
int main()
{
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	buildTree(0,0,n-1,a);
	while(q--)
	{
		int k;cin>>k;
		cout<<query(0,0,n-1,k)+1<<endl;
	}
}
