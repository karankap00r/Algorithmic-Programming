#include<bits/stdc++.h>
using namespace std;
bool vis[100];
vector<int> g[100];
void dfs(int x,int depth)
{
    if(vis[x])
        return;
    vis[x]=true;
    cout<<x<<"\n";
    for(int i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]])
        {
            for(int j=0;j<depth;j++)
            {
                cout<<"--->|";
            }
            dfs(g[x][i],depth+1);
            cout<<"\n";
        }
    }
}
int main()
{
    int n,i,x,y,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
    }
    int cnt=1;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"Forest "<<cnt<<"\n";
            dfs(i,1);
            cout<<"\n";
            cnt++;
        }
    }
    return 0;
}