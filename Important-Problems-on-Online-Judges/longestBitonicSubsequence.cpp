#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lbs(ll a[],ll n)
{
    ll *lis=(ll*)malloc(sizeof(ll)*(n+1));
    ll *lds=(ll*)malloc(sizeof(ll)*(n+1));
    ll i,j;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
        lds[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i]&&lis[j]+1>lis[i])
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[i]&&lds[j]+1>lds[i])
            {
                lds[i]=lds[j]+1;
            }
        }
    }
    ll ans=-1;
    for(i=0;i<n;i++)
    {
        ans=max(ans,lis[i]+lds[i]-1);
    }
    free(lis);
    free(lds);
    return ans;
}
int main()
{
    ll n,a[1000],i,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ans=lbs(a,n);
    cout<<ans;
    return 0;
}