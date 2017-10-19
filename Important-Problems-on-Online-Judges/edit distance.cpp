#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000][1000];
ll calc(char *s1,char *s2,ll m,ll n)
{
    if(m==0)
        return dp[m][n]=n;
    if(n==0)
        return dp[m][n]=m;
    if(dp[m][n]!=-1)
        return dp[m][n];
    if(s1[m-1]==s2[n-1])
        return dp[m][n]=calc(s1,s2,m-1,n-1);
    return dp[m][n]=1+min(min(calc(s1,s2,m-1,n),calc(s1,s2,m,n-1)),calc(s1,s2,m-1,n-1));
}
ll calcBU(char *s1,char *s2,ll m,ll n)
{
    ll i=0;
    ll j=0;
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    ll ans;
    ll m,n;
    char *s1,*s2;
    s1=(char*)malloc(sizeof(char)*100);
    s2=(char*)malloc(sizeof(char)*100);
    cin>>s1>>s2;
    m=strlen(s1);
    n=strlen(s2);
    memset(dp,-1,sizeof(dp));
    ans=calc(s1,s2,m,n);
    cout<<ans<<"\n";
    cout<<calcBU(s1,s2,m,n);
    return 0;
}