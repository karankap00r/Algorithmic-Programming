#include<bits/stdc++.h>
using namespace std;
int bs(int a[],int l,int r)
{
    if(l>r)
        return -1;
    int m=(l+r)/2;
    if((m==l&&a[m]>a[m+1])||(m==r&&a[m]>=a[m-1])||(a[m]>=a[m-1]&&a[m]>=a[m+1]))
        return a[m];
    else if(a[m]<a[m-1])
    {
        return bs(a,l,m-1);
    }
    else
    {
        return bs(a,m+1,r);
    }
}
int main()
{
    int n,a[1000],i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<bs(a,0,n-1);
    return 0;
}