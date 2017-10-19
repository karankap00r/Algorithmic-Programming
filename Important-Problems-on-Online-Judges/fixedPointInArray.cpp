#include<bits/stdc++.h>
using namespace std;
int fp(int a[],int l,int r)
{
    if(l>r)
        return -1;
    if(l==r)
        return (a[l]==l)?l:-1;
    int m=l+(r-l)/2;
    if(a[m]<m)
    {
        return fp(a,m+1,r);
    }
    else if(a[m]>m)
    {
        return fp(a,l,m-1);
    }
    else
    {
        return m;
    }
}
int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<fp(a,0,n-1);
    return 0;
}