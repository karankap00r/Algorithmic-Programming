// To check if an edge will be a part of any MST 
// Problem Link : https://www.hackerearth.com/problem/algorithm/to-buy-or-not-to-buy-6/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> > adj[1009];
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
bool ans;
bool visited[1009];
void dfs(ll i,ll x,ll dest)
{
    visited[i]=true;
    if(i==dest)
        ans=true;
    for(ll j=0;j<adj[i].size();j++)
    {
        if(!visited[adj[i][j].first]&&adj[i][j].second<x)
        {
            dfs(adj[i][j].first,x,dest);
        }
    }
}
ll temp[1009][1009];
int main()
{
    ll x, y;
    ll t,n,k,wt,q,num,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>k;
        for(i=1;i<=k;i++)
        {
            cin>>x>>y>>wt;
            adj[x].push_back(make_pair(y,wt));
            adj[y].push_back(make_pair(x,wt));
            temp[x][y]=wt;
            temp[y][x]=wt;
        }
        cin>>q;
        num=0;
        for(i=1;i<=q;i++)
        {
            memset(visited,false,sizeof(visited));
            ans=false;
            cin>>x>>y;
            dfs(x,temp[x][y],y);
            if(!ans)
            {
                num++;
                cout<<x<<" "<<y<<"\n";
            }
        }
        cout<<num/gcd(num,q)<<"/"<<q/gcd(num,q)<<"\n";
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        memset(temp,0,sizeof(temp));
    }
    return 0;
}

