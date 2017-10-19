#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],mn,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mn=INT_MAX;
    ans=0;
    for(i=0;i<n;i++)
    {
        mn=min(mn,a[i]);
        ans=max(ans,a[i]-mn);
    }
    cout<<ans;
    return 0;
}