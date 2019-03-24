#include<bits/stdc++.h>
using namespace std;
bool vis[202];
int level[202]={0};
unordered_map<int,vector<int>> m;
queue<int> Q;
void BFS(int i)
{
	Q.push(i);
	vis[i]=true;
	level[i]=1;
	while(!Q.empty())
	{
		auto y = Q.front();
		
		cout<<y<<" "<<level[y]<<endl;
		
		Q.pop();
		for(auto x = m[y].begin();x!=m[y].end();x++)
		{
			if(!vis[*x])
			{
				Q.push(*x);
				level[*x]=level[y]+1;
				vis[*x]=true;
			}
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=8;i++)
	{
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	BFS(1); // 1 is the source node
}
/* apparent structure of graph
                  1
               /  |  \
              2   3   4
             /   / \   \
            5  100 200  99
                          \
                            61
			 */
