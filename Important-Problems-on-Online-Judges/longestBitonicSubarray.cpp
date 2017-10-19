#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[100],l[100],r[100],ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l[0]=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        {
            l[i]=l[i-1]+1;
        }
        else
        {
            l[i]=1;
        }
    }
    r[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>=a[i+1])
        {
            r[i]=r[i+1]+1;
        }
        else
        {
            r[i]=1;
        }
    }
    ans=-1;
    for(i=0;i<n;i++)
    {
        ans=max(ans,r[i]+l[i]-1);
    }
    cout<<ans;
    return 0;
}