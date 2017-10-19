#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000][1000];
ll calc(ll a[],ll i,ll j)
{
    if(i==j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll mn=INT_MAX;
    for(ll k=i;k<j;k++)
    {
        mn=min(mn,a[i-1]*a[k]*a[j]+calc(a,i,k)+calc(a,k+1,j));
    }
    return dp[i][j]=mn;
}
ll calcBU(ll a[],ll n)
{
    ll i,j,k,l;
    for(i=0;i<n;i++)
    {
        dp[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    return dp[1][n-1];
}
int main()
{
    ll a[]={1,2,3,4};
    ll n=sizeof(a)/sizeof(ll);
    memset(dp,-1,sizeof(dp));
    ll sum=calc(a,1,n-1);
    cout<<sum<<"\n";
    memset(dp,0,sizeof(dp));
    cout<<calcBU(a,n)<<"\n";
    return 0;
}