#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll calc(ll a[],ll n)
{
    ll *l=(ll*)malloc(sizeof(ll)*(n+1));
    ll i,j;
    for(i=0;i<n;i++)
    {
        l[i]=a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i]&&l[j]+a[i]>l[i])
            {
                l[i]=l[j]+a[i];
            }
        }
    }
    ll ans=-1;
    for(i=0;i<n;i++)
    {
        ans=max(ans,l[i]);
    }
    free(l);
    return ans;
}
int main()
{
    ll n,i,a[1000],ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ans=calc(a,n);
    cout<<ans;
    return 0;
}