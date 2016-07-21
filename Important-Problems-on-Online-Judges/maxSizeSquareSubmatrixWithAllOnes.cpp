#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c,i,j,a[100][100],dp[100][100],ans;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[0][0]=a[0][0];
    for(i=1;i<r;i++)
    {
        dp[i][0]=a[i][0];
    }
    for(i=1;i<c;i++)
    {
        dp[0][i]=a[0][i];
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(a[i][j])
            {
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    ans=-1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}