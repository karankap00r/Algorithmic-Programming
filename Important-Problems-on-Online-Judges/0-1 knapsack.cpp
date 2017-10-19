#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000][100];
ll calc(ll wt[],ll val[],ll n,ll W)
{
    if(W<0||n<0)
        return INT_MIN;
    if(W==0||n==0)
        return dp[n][W]=0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    return dp[n][W]=max(calc(wt,val,n-1,W),val[n]+calc(wt,val,n-1,W-wt[n]));
}
ll calcBU(ll wt[],ll val[],ll n,ll W)
{
    ll i,j;
    ll memo[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
            {
                memo[i][j]=0;
            }
            else if(wt[i]<=j)
            {
                memo[i][j]=max(memo[i-1][j],val[i]+memo[i-1][j-wt[i-1]]);
            }
            else
            {
                memo[i][j]=memo[i-1][j];
            }
        }
    }
    return memo[n][W];
}
int main()
{
    ll n,W,i,ans,wt[100],val[100];
    cin>>n>>W;
    for(i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    ans=calc(wt,val,n-1,W);
    cout<<ans<<"\n";
    cout<<calcBU(wt,val,n,W);
    return 0;
}