#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,j,k;
    ll g[][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    for(k=0;k<4;k++)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(g[i][k]!=INT_MAX&&g[k][j]!=INT_MAX)
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}