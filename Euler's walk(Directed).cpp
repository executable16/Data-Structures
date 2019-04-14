		#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> m;
unordered_map<int,int> c;
vector<int> circuit;
stack <int> s;
void dfs(int x)
{
	s.push(x);
	
	while(!s.empty())
	{
		auto curr=s.top();
		if(c[curr])
		{
			auto next=m[curr].back();
			m[curr].pop_back();
			c[curr]--;
			s.push(next);
		}
		else
		{
			circuit.push_back(curr);
			s.pop();
		}
	}
	
}
int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=1;i<=e;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		c[a]++;
	}
	dfs(0);
	for(int i=circuit.size()-1;i>=0;i--)
		cout<<circuit[i]<<"---->";
}
