#include<bits/stdc++.h>
using namespace std;
#define ll long long
void printAll(ll **a,ll i,ll j,ll r,ll c,ll path[],ll pathlen)
{
    if(i==r-1)
    {
        for(ll k=0;k<pathlen;k++)
        {
            cout<<path[k]<<" ";
        }
        while(j<c)
        {
            cout<<a[r-1][j++]<<" ";
        }
        cout<<"\n";
    }
    else if(j==c-1)
    {
        for(ll k=0;k<pathlen;k++)
        {
            cout<<path[k]<<" ";
        }
        while(i<r)
        {
            cout<<a[i++][c-1]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        path[pathlen++]=a[i][j];
        printAll(a,i+1,j,r,c,path,pathlen);
        printAll(a,i,j+1,r,c,path,pathlen);
    }
}
int main()
{
    ll r,c,i,j;
    cin>>r>>c;
    ll **a=(ll**)malloc(sizeof(ll*)*(r+1));
    for(i=0;i<=r;i++)
    {
        a[i]=(ll*)malloc(sizeof(ll*)*(c+1));
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    ll path[100];
    printAll(a,0,0,r,c,path,0);
    return 0;
}