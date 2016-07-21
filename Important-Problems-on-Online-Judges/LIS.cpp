#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ans,n,i,j,a[100],l[100],prev[100],init;
    stack<int> s;
    ans=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        l[i]=1;
        prev[i]=-1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&l[i]<l[j]+1)
            {
                prev[i]=j;
                l[i]=l[j]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(l[i]>ans)
        {
            init=i;
            ans=l[i];
        }
    }
    cout<<ans<<"\n";
    while(init>=0)
    {
        s.push(a[init]);
        init=prev[init];
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}