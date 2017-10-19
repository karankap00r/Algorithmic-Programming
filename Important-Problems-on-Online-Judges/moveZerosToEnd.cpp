#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l=0;
    int r=n-1;
    while(l<r)
    {
        while(l<r&&a[l]!=0)
        {
            l++;
        }
        while(r>=0&&a[r]==0)
        {
            r--;
        }
        if(l<r)
        {
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}