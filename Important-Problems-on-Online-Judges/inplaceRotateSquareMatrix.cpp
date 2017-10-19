#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,a[100][100],x,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(x=0;x<n/2;x++)
    {
        for(y=0;y<n-x-1;y++)
        {
            ll temp=a[x][y];
            a[x][y]=a[y][n-1-x];
            a[y][n-1-x]=a[n-1-x][n-1-y];
            a[n-1-x][n-1-y]=a[n-1-y][x];
            a[n-1-y][x]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}