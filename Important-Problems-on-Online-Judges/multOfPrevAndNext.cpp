#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,a[1000],prev,cur;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    prev=a[0];
    a[0]*=a[1];
    for(i=1;i<n-1;i++)
    {
        cur=a[i];
        a[i]=prev*a[i+1];
        prev=cur;
    }
    a[n-1]*=prev;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}