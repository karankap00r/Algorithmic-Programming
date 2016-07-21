#include<bits/stdc++.h>
using namespace std;
int fs(int a[],int l,int r,int x)
{
    if(l>r)
        return -1;
    if(l==r)
        return a[l]<=x;
    int m=l+(r-l)/2;
    if(a[m]>x)
    {
        return fs(a,l,m-1,x);
    }
    else
    {
        if(m==r||(m<r&&a[m+1]>x))
        {
            return m;
        }
        else
        {
            return fs(a,m+1,r,x);
        }
    }
}
int main()
{
    int n,i,a[100],x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    cout<<fs(a,0,n-1,x);
    return 0;
}