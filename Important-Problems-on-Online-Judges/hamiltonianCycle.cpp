#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[1000];
bool solve(ll g[100][100],ll cur,ll tot,ll v,ll path[])
{
    if(tot==v)
    {
        if(g[path[tot-1]][0]==1)
        {
            for(ll i=0;i<tot;i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<path[0];
            cout<<"\n";
        }
        return (g[path[tot-1]][0]==1);
    }
    else
    {   
        for(ll i=1;i<v;i++)
        {
            if((!vis[i])&&g[cur][i])
            {
                vis[i]=1;
                path[tot]=i;
                if(solve(g,i,tot+1,v,path))
                {
                    return true;
                }
                vis[i]=0;
            }
        }
    }
    return false;
}
int main()
{
    ll i,j,v;
    ll g[100][100];
    cin>>v;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cin>>g[i][j];
        }
    }
    ll path[100];
    vis[0]=1;
    path[0]=0;
    bool ans=solve(g,0,1,v,path);
    if(!ans)
    {
        cout<<"No Hamiltonian cycle";
    }
    return 0;
}