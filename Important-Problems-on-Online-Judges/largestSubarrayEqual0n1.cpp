#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],ans,hash[10000],sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            a[i]=-1;
        }
    }
    ans=0;
    for(i=0;i<1000;i++)
    {
        hash[i]=-2;
    }
    hash[0]=-1;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(hash[sum]==-2)
        {
            hash[sum]=i;
        }
        else
        {
            ans=max(ans,i-hash[sum]);
        }
    }
    cout<<ans;
    return 0;
}