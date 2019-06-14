#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> v; 
    
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }

    int x = 0;
    for(int i=0;i<n;i++)
        x=x^v[i];

    int count=0;

    while(x>0)
    {
        int k = x%2;
        if(k)
            break;
        count++;
        x=x/2;
    }
    int xx=0,yy=0;
    for(int i=0;i<n;i++)
    {
        int zz = v[i]>>count;
        if(zz&1)
            xx=xx^v[i];
        else
            yy=yy^v[i];
    }
    cout<<xx<<" "<<yy<<endl;



}
