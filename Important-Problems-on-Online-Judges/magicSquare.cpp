#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,x,y,i,sol[100][100];
    cin>>n;
    x=n/2;
    y=n-1;
    memset(sol,-1,sizeof(sol));
    for(i=1;i<=n*n;)
    {
        if(x==-1&&y==n)
        {
            x=0;
            y=n-2;
        }
        else if(x==-1)
        {
            x=n-1;
        }
        else if(y==n)
        {
            y=0;
        }
        else if(sol[x][y]!=-1)
        {
            x++;
            y-=2;            
        }
        else
        {
            sol[x][y]=i;
            x--;
            y++;
            i++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}