#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000009
vector<ll> v[90000];
ll sieve[MAX],fact[MAX],a[MAX];
void smallest_factor()
{
    ll i,j;
    for(i=2;i*i<=MAX;i++)
    {
        if(sieve[i]==0)
        {
            sieve[i]=i;
            for(j=i;i*j<=MAX;j++)
            {
                if(sieve[i*j]==0)
                {
                    sieve[i*j]=i;
                }
            }
        }
    }
    while(i<=MAX)
    {
        if(sieve[i]==0)
        {
            sieve[i]=i;
        }
        i++;
    }
}
ll sumofpower(ll x)
{
    ll cnt=0;
    ll temp;
    while(x!=1)
    {
        temp=sieve[x];
        while(x%temp==0)
        {
            x/=temp;
            cnt++;
        }
    }
    return cnt;
}
void calc_fact()
{
    fact[1]=0;
    for(ll i=2;i<=1000009;i++)
    {
        fact[i]=fact[i-1]+sumofpower(i);
    }
}
int main()
{
    smallest_factor();
    calc_fact();
    ll n,i,k,j,len,temp,sum,res;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    k=1<<n;
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                v[i].push_back(a[j]);
            }
        }
    }
    res=0;
    for(i=0;i<k;i++)
    {
        sum=0;
        len=v[i].size();
        for(j=0;j<len;j++)
        {
            temp=v[i][j];
            sum+=fact[temp];
        }
        if(sum%2==0)
        {
            res+=sum;
        }
    }
    cout<<res;
    return 0;
}
