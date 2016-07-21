#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,a[100],b[100],m,last,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(i=m-1;i>=0;i--)
    {
        if(b[i]<a[n-1])
        {
            last=a[n-1];
            for(j=n-2;j>=0;j--)
            {
                if(a[j]<b[i])
                    break;
                a[j+1]=a[j];
            }
            a[j+1]=b[i];
            b[i]=last;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    for(i=0;i<m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}