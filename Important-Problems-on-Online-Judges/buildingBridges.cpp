#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ans,i,n,a[1000],m[10000],b[1000],j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i+1;
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    ll *l=(ll*)malloc(sizeof(ll)*(n+1));
    for(i=0;i<n;i++)
    {
        l[i]=1;
    }
    ans=-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(m[b[j]]<m[b[i]]&&l[j]+1>l[i])
            {
                l[i]=l[j]+1;
            }
        }
        ans=max(ans,l[i]);
    }
    cout<<ans;
    return 0;
}