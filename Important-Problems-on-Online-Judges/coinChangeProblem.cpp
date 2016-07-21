#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100000][1000];
ll calc(ll a[],ll pos,ll n,ll sum)
{
    if(sum<0||(sum>0&&pos==n))
    {
        return 0;
    }
    if(dp[sum][pos]!=-1)
    {
        return dp[sum][pos];
    }
    if(pos==n||sum==0)
    {
        return dp[sum][pos]=1;
    }
    ll ways=calc(a,pos,n,sum-a[pos])+calc(a,pos+1,n,sum);
    return dp[sum][pos]=ways;
}
void Print(ll a[],ll n,ll sum,ll pos,ll soln[],ll pathlen)
{
    if(sum<0||(pos==n&&sum>0))
    {
        return;
    }
    if(pos==n||sum==0)
    {
        for(ll i=0;i<pathlen;i++)
        {
            cout<<soln[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    else
    {
        if(calc(a,pos,n,sum-a[pos])!=0)
        {
            soln[pathlen]=a[pos];
            Print(a,n,sum-a[pos],pos,soln,pathlen+1);
        }
        if(calc(a,pos+1,n,sum)!=0)
        {
            Print(a,n,sum,pos+1,soln,pathlen);
        }
    }
}
ll calcBU(ll a[],ll sum,ll n)
{
    ll i,j;
    ll dp[sum+1][n+1];
    for(i=0;i<n;i++)
    {
        dp[0][i]=1;        
    }
    for(j=1;j<=sum;j++)
    {
        for(i=0;i<n;i++)
        {
            if(j>=a[i])
            {
                dp[j][i]+=dp[j-a[i]][i];
            }
            if(i>=1)
            {
                dp[j][i]+=dp[j][(i-1)];
            }
        }        
    }
    return dp[sum][n];
}
ll calc1D(ll a[],ll sum,ll n)
{
    ll i,j;
    ll table[sum+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=a[i];j<=sum;j++)
        {
            table[j]+=table[j-a[i]];
        }
    }
    return table[sum];
}
int main()
{
    ll n,sum,i,a[100],ans;
    cin>>n>>sum;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    ans=calc(a,0,n,sum);
    cout<<ans<<"\n";
    cout<<calcBU(a,sum,n)<<"\n";
    cout<<calc1D(a,sum,n);
    cout<<"\n";
    ll soln[1000];
    Print(a,n,sum,0LL,soln,0LL);
    cout<<"\n";
    
    return 0;
}