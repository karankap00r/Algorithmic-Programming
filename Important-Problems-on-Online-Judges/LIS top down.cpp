#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000];
ll LIS(ll a[],ll n,ll *max_ref)
{
    if(n==1)
        return dp[n-1]=1;
    if(dp[n-1]!=-1)
    {
        return dp[n-1];
    }
    ll res;
    dp[n-1]=1;
    for(ll i=1;i<n;i++)
    {
        res=LIS(a,i,max_ref);
        if(a[i-1]<a[n-1])
        {
            dp[n-1]=max(dp[n-1],1+res);
        }
    }
    *max_ref=max(*max_ref,dp[n-1]);
    return dp[n-1];
}
int main()
{
    ll ans,n,i,j,a[100];
    stack<int> s;
    ans=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        dp[i]=-1;
    }
    LIS(a,n,&ans);
    cout<<ans<<"\n";
    return 0;
}