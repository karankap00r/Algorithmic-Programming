#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll dp[100][100];
ll calc(ll r,ll c)
{
    if(r<1||c<1)
        return 0;
    if(r==1&&c==1)
        return dp[r][c]=1;
    if(dp[r][c]!=-1)
        return dp[r][c];
    return dp[r][c]=calc(r-1,c)+calc(r,c-1);
}
int main()
{
    ll r,c,ans;
    cin>>r>>c;
    memset(dp,-1,sizeof(dp));
    ans=calc(r,c);
    cout<<ans;
    return 0;
}