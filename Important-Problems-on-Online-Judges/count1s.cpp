#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bs(ll a[],ll l,ll r)
{
    if(l>r)
        return 0;
    ll m=(l+r)/2;
    if(a[m]==0)
        return bs(a,l,m-1);
    else
    {
        if(m==r||a[m+1]==0)
        {
            return m+1;
        }
        else
        {
            return bs(a,m+1,r);
        }
    }
}
int main()
{
    ll n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<bs(a,0,n-1);
    return 0;
}