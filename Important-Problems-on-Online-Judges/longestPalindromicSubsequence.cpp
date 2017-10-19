#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000][1000];
ll calc(string s,ll i,ll j)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j)
        return dp[i][j]=1;
    if(s[i]==s[j])
        return dp[i][j]=2+calc(s,i+1,j-1);
    else
        return dp[i][j]=max(calc(s,i+1,j),calc(s,i,j-1));
}
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    memset(dp,-1,sizeof(dp));
    cout<<calc(s,0,n-1);
    return 0;
}