#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int calc(int a[],int pos,int n)
{
    if(pos>n||a[pos]==0)
    {
        return INT_MAX;
    }
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    if(pos==n)
    {
        return dp[pos]=0;
    }
    int mn=INT_MAX;
    for(int i=1;i<=a[pos];i++)
    {
        int temp=calc(a,pos+i,n);
        if(temp!=INT_MAX)
        {
            mn=min(mn,1+temp);
        }
    }
    return dp[pos]=mn;
}
int main()
{
    int n,a[100],i,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    ans=calc(a,0,n);
    cout<<ans;
    return 0;
}