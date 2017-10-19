#include<bits/stdc++.h>
using namespace std;
int median(int a[],int sz)
{
    int n=sz;
    if(n%2==0)
    {
        return (a[n/2]+a[(n/2)-1])/2;
    }
    else
    {
        return a[n/2];
    }
}
int getMedian(int a[],int b[],int sz)
{
    if(sz<=0)
        return -1;
    if(sz==1)
        return (a[0]+b[0])/2;
    if(sz==2)
        return (min(a[1],b[1])+max(a[0],b[0]))/2;
    int m1=median(a,sz);
    int m2=median(b,sz);
    if(m1==m2)
    {
        return m1;
    }
    else
    {
        if(m1>m2)
        {
            if(sz%2==0)
                return getMedian(b+sz/2-1,a,sz-sz/2+1);
            else
                return getMedian(b+sz/2,a,sz-sz/2);
        }
        else
        {
            if(sz%2==0)
                return getMedian(a+sz/2-1,b,sz-sz/2+1);
            else
                return getMedian(a+sz/2,b,sz-sz/2);
        }
    }
}
int main()
{
    int n,i,a[100],b[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<getMedian(a,b,n);
    return 0;
}