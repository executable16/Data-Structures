#include<bits/stdc++.h>
using namespace std;
void construct_tree(int a[],int segtree[],int index,int start,int end)
{
	if(start>end)
		return;

	if(start==end)
	{
		segtree[index]=a[start];
		return;
	}

	int mid = (start+end)/2;
	construct_tree(a,segtree,2*index+1,start,mid);
	construct_tree(a,segtree,2*index+2,mid+1,end);
	segtree[index]=min(segtree[2*index+1],segtree[2*index+2]);
}
int query(int a[],int segtree[],int index,int start,int end,int l,int r)
{
	if(start > r || end < l) // No overlap
		return INT_MAX;
	if(l <= start && r >= end) // complete overlap
		return segtree[index];
	int mid=(start+end)/2;
	return min(query(a,segtree,2*index+1,0,mid,l,r),query(a,segtree,2*index+2,mid+1,end,l,r));
}
void update(int a[],int segtree[],int index,int start,int end,int pos,int val)
{
	if(pos< start || pos > end)
		return;
	if(start == end)
	{
		segtree[index]=val;
		return;
	}
	int mid=(start+end)/2;
	update(a,segtree,2*index+1,0,mid,pos,val);
	update(a,segtree,2*index+2,0,mid,pos,val);
	segtree[index]=min(segtree[2*index+1],segtree[2*index+2]);
	return;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *segtree = new int[4*n];
	construct_tree(a,segtree,0,0,n-1);
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,c;
		cin>>c>>l>>r;
		if(c==1){
		--l,--r;
		cout<<query(a,segtree,0,0,n-1,l,r)<<endl;
	}
	else
		{
			--l;
			update(a,segtree,0,0,n-1,l,r);
		}
	}
	/*for(int i=0;i<2*n-1;i++)
		cout<<segtree[i]<<" ";*/
}
