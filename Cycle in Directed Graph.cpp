// Codeforces problem : http://codeforces.com/problemset/problem/510/B
//DFS function finds if there is a cycle 
//There is a cycle if we visit an already visited node 
//ie there are two paths to that node
// so if we reach a node again the node we came from 
// then we return from the function
// so that a back edge is not counted as cycle.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool visited[60][60];
char grid[60][60];
bool ans;
ll n,m;
void dfs(ll i,ll j,ll prevx,ll prevy,ll color)
{
    if(i<1||i>n||j<1||j>m)
        return;
    if(grid[i][j]!=color)
        return;
    if(visited[i][j])
    {
        ans=true;
        return;
    }
    visited[i][j]=true;
    if(!(prevx==i-1&&prevy==j))
    {
        dfs(i-1,j,i,j,color);
    }
    if(!(prevx==i+1&&prevy==j))
    {
        dfs(i+1,j,i,j,color);
    }
    if(!(prevx==i&&prevy==j-1))
    {
        dfs(i,j-1,i,j,color);
    }
    if(!(prevx==i&&prevy==j+1))
    {
        dfs(i,j+1,i,j,color);
    }
}
int main()
{
    ll i,j;
    string s;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        for(j=1;j<=m;j++)
        {
            grid[i][j]=s[j-1];
        }
    }
    ans=false;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!visited[i][j])
            {
                dfs(i,j,-1,-1,grid[i][j]);
            }
        }
    }
    if(ans==true)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
