#include<bits/stdc++.h>
using namespace std;
int bs(auto v , int beg , int end , int val, int search_type)
{
	int result = -1;
	while(beg<=end)
	{
		if(beg > end)
			return -1;
		int mid = (beg + ( end - beg )/2 );
		if(v[mid]==val && !search_type)
		{
			end = mid-1;
			result = mid;
		}
		else if(v[mid]==val && search_type)
		{
			beg= mid+1;
			result = mid;
		}
		else if(v[mid] > val)
		{
			end = mid-1;
		}
		else
			beg = mid + 1;
	}
	return result;
}


int main()
{
	
	system("clear");
	cout<<"Ran successfully\n";
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int l = bs(v,0,v.size(),k,0);
	if(l<0)
		return 0;
	int r = bs(v,0,v.size(),k,1);
	cout<<l<<" "<<r<<endl;
}
