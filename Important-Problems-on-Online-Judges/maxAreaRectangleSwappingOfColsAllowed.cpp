#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c,i,j,hist[100][100],a[100][100];
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<c;i++)
    {
        hist[0][i]=a[0][i];
    }
    for(i=1;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            hist[i][j]=(a[i][j]==0)?0:hist[i-1][j]+1;
        }
    }
    for(ll i=0; i<r; i++)
    {
        ll count[r+1]={0};
        for(ll j=0;j<c;j++)
            count[hist[i][j]]++;
        ll col_no=0;
        for(ll j=r;j>=0;j--)
        {
            if(count[j]>0)
            {
                for(ll k=0;k<count[j];k++)
                {
                    hist[i][col_no]=j;
                    col_no++;
                }
            }
        }
    }
    ll mx=-1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mx=max(mx,hist[i][j]*(j+1));
        }
    }
    cout<<mx;
    return 0;
}