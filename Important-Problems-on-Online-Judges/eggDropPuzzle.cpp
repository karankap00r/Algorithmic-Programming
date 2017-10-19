#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[10000][1000];
ll calc(ll n,ll k)
{
    if(n==1)
        return dp[n][k]=k;
    if(k==1||k==0)
        return dp[n][k]=k;
    if(dp[n][k]!=-1)
        return dp[n][k];
    ll res=INT_MAX;
    for(ll x=1;x<=k;x++)
    {
        res=min(res,max(calc(n-1,x-1),calc(n,k-x)));
    }
    return dp[n][k]=(res+1);
}
ll calcBU(ll n,ll k)
{
    ll i,j,egg[n+1][k+1];
    for(i=1;i<=k;i++)
    {
        egg[1][i]=i;
        egg[0][i]=INT_MAX;
    }
    for(i=1;i<=n;i++)
    {
        egg[i][0]=0;
        egg[i][1]=1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            egg[i][j]=INT_MAX;
            for(ll x=1;x<=j;x++)
            {
                egg[i][j]=min(egg[i][j],1+max(egg[i-1][x-1],egg[i][j-x]));
            }
        }
    }
    return egg[n][k];
}
int main()
{
    ll n,k,ans;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ans=calc(n,k);
    cout<<ans<<"\n";
    cout<<calcBU(n,k);
    return 0;
}