#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,sum,i,a[1000],l,r;
    cin>>n>>sum;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    l=0;
    r=n-1;
    while(l<r)
    {
        if(a[l]+a[r]<sum)
        {
            l++;
        }
        else if(a[l]+a[r]>sum)
        {
            r--;
        }
        else
        {
            cout<<"A pair has been found";
            return 0;
        }
    }
    return 0;
}