#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

const ull MOD=1e9+7;
const int INF = 0x3f3f3f3f;// for integer only

#define PI 3.1415926535897932384626
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define debug(x) cout << (#x) << " is " << (x) << endl
#define rep(i,j,k) for(int i=j;i<k;i++)
#define TC int tc;cin>>tc;while(tc--)
#define umap unordered_map
#define uset unordered_set
#define vi vector<int>
#define pb emplace_back
#define po pop_back
#define vsort(x) sort(x.begin(),x.end())
#define vrsort(x) sort(x.begin(),x.end(),greater<int>())
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define odd(x) (x & 1)
#define even(x) (!odd(x))
#define  timer clock_t start, end;
#define time double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 

int BLOCK;

struct MO{
	int L;
	int R;
	string queryString;
	int id;
};

vector<string> v;

unordered_map<string,int> m;

bool comp(MO x , MO y){
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int index){
	m[v[index]]++;
}
void remove(int index){
	m[v[index]]--;
}
int main(){
	flash;
	int n;
	cin>>n;
	
	BLOCK = sqrt(n);
	
	v.resize(n);
	
	for(auto &x : v){
		cin>>x;
	}

	int query;
	cin>>query;

	vector<MO> Q(query);

	for(int i = 0 ; i < query ; i++){
		cin>>Q[i].L;
		cin>>Q[i].R;
		cin>>Q[i].queryString;
		Q[i].id = i;
		--Q[i].L , --Q[i].R;
	}

	vector<int> answer(query);

	sort(Q.begin(),Q.end(),comp);

	int currentL = 0, currentR = 0;

	for(int i = 0 ; i < query ; i++){
		int L = Q[i].L;
		int R = Q[i].R;
		string currentString = Q[i].queryString;
		int queryNumber = Q[i].id;

		while(currentL < L){
			remove(currentL);
			currentL++;
		}
		while(currentL > L){
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R){
			add(currentR);
			currentR++;
		}
		while(currentR > R+1){
			remove(currentR-1);
			currentR--;
		}
		answer[queryNumber]=m[currentString];
	}
	rep(i,0,query){
		cout<<answer[i]<<endl;
	}
}
