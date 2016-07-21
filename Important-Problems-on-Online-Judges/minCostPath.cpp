#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r,c,dp[100][100];
ll calc(ll a[][100],ll i,ll j,ll x,ll y)
{
    if(i>=r||j>=c)
        return INT_MAX;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==x&&j==y)
        return dp[i][j]=a[x][y];
    return dp[i][j]=a[i][j]+min(min(calc(a,i,j+1,x,y),calc(a,i+1,j,x,y)),calc(a,i+1,j+1,x,y));
}
ll calcBU(ll a[][100],ll x,ll y)
{
    ll i,j;
    ll dp[r+1][c+1];
    dp[0][0]=a[0][0];
    for(i=1;i<r;i++)
        dp[i][0]=dp[i-1][0]+a[i][0];
    for(i=1;i<c;i++)
        dp[0][i]=dp[0][i-1]+a[0][i];
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            dp[i][j]=a[i][j]+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    return dp[x][y];
}
int main()
{
    ll p1,p2,a[100][100],i,j,ans;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>p1>>p2;
    memset(dp,-1,sizeof(dp));
    ans=calc(a,0,0,p1,p2);
    cout<<ans<<"\n";
    cout<<calcBU(a,p1,p2);
    return 0;
}