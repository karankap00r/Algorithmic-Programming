#include<bits/stdc++.h>
using namespace std;
int lb(int a[],int l,int r,int x)
{
    if(l>r)
        return -1;
    if(l==r)
        return (a[l]==x);
    int m=(l+r)/2;
    if(a[m]<x)
    {
        return lb(a,m+1,r,x);
    }
    else if(a[m]>x)
    {
        return lb(a,l,m-1,x);
    }
    else
    {
        if(m==l||(l<m&&a[m-1]<x))
        {
            return m;
        }
        else
        {
            return lb(a,l,m-1,x);
        }
    }
}
int ub(int a[],int l,int r,int x)
{
    if(l>r)
        return -1;
    if(l==r)
        return a[l]==x;
    int m=l+(r-l)/2;
    if(a[m]>x)
    {
        return ub(a,l,m-1,x);
    }
    else if(a[m]<x)
    {
        return ub(a,m+1,r,x);
    }
    else
    {
        if(m==r||(m<r&&a[m+1]>x))
        {
            return m;
        }
        else
        {
            return ub(a,m+1,r,x);
        }
    }
}
bool isMajority(int a[],int n,int x)
{
    int l=lb(a,0,n-1,x);
    if(l==-1)
    {
        return 0;
    }
    int r=ub(a,0,n-1,x);
    return (r-l+1)>=n/2;
}
int main()
{
    int n,i,x,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    if(isMajority(a,n,x))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}