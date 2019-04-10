#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> m;
int parent[10005];
int low[10005];
int disc[10005];
bool vis[10005];
vector<pair<int,int>> bridges;
int timer=0;
void dfs(int u)
{
  vis[u]=true;
  low[u]=disc[u]=++timer;
  for(auto x : m[u])
  { 
    if(x==parent[u])
      continue;

      if(!vis[x])
        {
          //child[u]++;
          parent[x]=u;
          dfs(x);
          low[u]=min(low[u],low[x]);
          if(low[x]>disc[u])
            bridges.push_back({u,x});
        }
      else
      {
        low[u]=min(low[u],disc[x]);
      }
  }
}
int main()
{
  int V,E;
  cin>>V>>E;
  for(int i=1;i<=E;i++)
  {
    int a,b;
    cin>>a>>b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  parent[1]=-1;
  //dfs(1);
  
  //ap[1] = child[1]>1 ? true : false; 
 
  for(auto x : bridges)
  {
    cout<<x.first<<" "<<x.second<<endl;
  }
}
