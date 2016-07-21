#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
ll vis[100][100],r,c,a[100][100];
bool isvalid(ll i,ll j)
{
    return i>=0&&j>=0&&i<r&&j<c;
}
void dfs(ll i,ll j)
{
    vis[i][j]=true;
    for(ll k=0;k<4;k++)
    {
        ll ni=i+dx[k];
        ll nj=j+dy[k];
        if(isvalid(ni,nj)&&vis[ni][nj]==false&&a[ni][nj]==1)
        {
            dfs(ni,nj);
        }
    }
    
}
int main()
{
    ll i,j,cnt;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    cnt=0LL;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(!vis[i][j]&&a[i][j]==1)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}