#include<bits/stdc++.h>
using namespace std;
int lazy[1000000]={0};
int segtree[1000000]={0};
void construct_tree(int a[],int segtree[],int pos,int start,int end)
{
	if(start>end)
		return;
	if(start==end)
	{
		segtree[pos]=a[start];
		return;
	}
	int mid=(start+end)/2;
	construct_tree(a,segtree,2*pos+1,start,mid);
	construct_tree(a,segtree,2*pos+2,mid+1,end);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
void update(int lazy[],int segtree[],int pos,int start,int end,int l,int r,int val)
{
	if(start>end)
		return;
	if(lazy[pos]!=0)
	{
		segtree[pos]+=lazy[pos];
		if(start!=end)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+1]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(r<start || end<l)
		return ;
	if(l<=start && end<=r) // total overlap
	{
		segtree[pos]+=val;
		if(start!=end)
		{
			lazy[2*pos+1]+=val;
			lazy[2*pos+2]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	update(lazy,segtree,2*pos+1,start,mid,l,r,val);
	update(lazy,segtree,2*pos+2,mid+1,end,l,r,val);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);

}
int query(int lazy[],int segtree[],int pos,int start,int end,int l,int r)
{
	if(start>end || r<start || end<l)
		return INT_MAX;
	if(lazy[pos]!=0)
	{
		
		segtree[pos]+=lazy[pos];
		if(start!=end)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	
	if(l<=start && end<=r)
		return segtree[pos];
	int mid=(start+end)/2;
	return min(query(lazy,segtree,2*pos+1,start,mid,l,r),query(lazy,segtree,2*pos+2,mid+1,end,l,r));
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	construct_tree(a,segtree,0,0,n-1);
	int q;
	cout<<"Enter the number of queries\n";
	cin>>q;
	cout<<"Query types are :\n";
	  cout<<"1 x y (Min in range [l,r])\n";
	  cout<<"2 x y z (Update in range[l,r] and add z to it\n";
	while(q--)
	{ 
		int x,y,z;
		cin>>x>>y>>z;
		--y,--z;
		if(x==1)
		{
			cout<<query(lazy,segtree,0,0,n-1,y,z)<<"\n";
		}
		else
		{	int val;
			cin>>val;
			update(lazy,segtree,0,0,n-1,y,z,val);
		}
	}
}
