#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> m;
int main()
{
    ll n,sum,i,a[1000],ans,temp;
    cin>>n>>sum;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    ans=0;
    for(i=0;i<n;i++)
    {
        temp=m[a[i]]*m[sum-a[i]];
        if(a[i]==sum-a[i])
        {
            temp=(m[a[i]]*(m[a[i]]-1))/2;
        }
        ans+=temp;
        m[a[i]]=0;
    }
    cout<<ans;
    return 0;
}