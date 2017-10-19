#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll kadanes(ll a[],ll n)
{
    ll cur_max=a[0],max_so_far=a[0];
    for(ll i=1;i<n;i++)
    {
        cur_max=max(cur_max+a[i],a[i]);
        max_so_far=max(max_so_far,cur_max);
    }
    return max_so_far;
}
int main()
{
    ll r,c,i,j,k,temp[1000],a[100][100];
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    ll mx=-1;
    for(i=0;i<c;i++)
    {
        memset(temp,0,sizeof(temp));
        for(j=i;j<c;j++)
        {
            for(k=0;k<r;k++)
            {
                temp[k]+=a[k][j];
            }
            mx=max(mx,kadanes(temp,r));
        }
    }
    cout<<mx;
    return 0;
}