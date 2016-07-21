#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,a[1000],mn,mx,k;
    mn=INT_MAX;
    mx=INT_MIN;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    sort(a,a+n);
    mn=a[0];
    mx=a[n-1];
    if(mx-mn<=k)
    {
        for(i=0;i<n;i++)
        {
            a[i]+=k;
        }
    }
    else
    {
        a[0]+=k;
        a[n-1]-=k;
        mx=max(a[0],a[n-1]);
        mn=min(a[0],a[n-1]);
        for(i=1;i<n-1;i++)
        {
            if(a[i]<mn)
            {
                a[i]+=k;
            }
            else if(a[i]>mx)
            {
                a[i]-=k;
            }
            else
            {
                if(a[i]-mn<mx-a[i])
                {
                    a[i]+=k;
                }
                else
                {
                    a[i]-=k;
                }
            }
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
    }
    cout<<mx-mn;
    return 0;
}