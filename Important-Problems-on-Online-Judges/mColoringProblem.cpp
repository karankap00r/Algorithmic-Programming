#include<bits/stdc++.h>
using namespace std;
bool isSafe(int g[100][100],int node,int tot,int c,int col[])
{
    int i;
    for(i=0;i<tot;i++)
    {
        if(g[node][i])
        {
            //cout<<node<<","<<i<<","<<col[node]<<"\n";
            if(col[i]==c)
            {
                return false;
            }
        }
    }
    return true;
}
bool color(int g[100][100],int pos,int n,int m,int col[100])
{
    int i;
    if(pos==n)
    {
        for(i=0;i<n;i++)
        {
            cout<<i<<"->"<<col[i]<<"\n";
        }
        return true;
    }
    else
    {
        for(i=0;i<m;i++)
        {
            if(isSafe(g,pos,n,i,col))
            {
                col[pos]=i;
                if(color(g,pos+1,n,m,col))
                {
                    return true;
                }
                col[pos]=-1;
            }
        }
    }
    return false;
}
int main()
{
    int n,i,j,g[100][100],col[100],m;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    memset(col,-1,sizeof(col));
    bool ans=color(g,0,n,m,col);
    if(!ans)
    {
        cout<<"The graph could not be colored with "<<m<<" colors";
    }
    return 0;
}