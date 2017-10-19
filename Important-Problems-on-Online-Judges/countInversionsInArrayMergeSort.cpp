#include<bits/stdc++.h>
using namespace std;
int merge1(int a[],int temp[],int l,int m,int r)
{
    int i=l;
    int j=m;
    int k=l;
    int invcnt=0;
    while(i<=m-1&&j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
            invcnt+=(m-i);
        }
    }
    while(i<=m-1)
    {
        temp[k++]=a[i++];
    }
    while(j<=r)
    {
        temp[k++]=a[j++];
    }
    for(int i=l;i<=r;i++)
    {
        a[i]=temp[i];
    }
    return invcnt;
}
int ms(int a[],int temp[],int l,int r)
{
    int invcnt=0;
    if(r>l)
    {
        int m=(l+r)/2;
        invcnt=ms(a,temp,l,m);
        invcnt+=ms(a,temp,m+1,r);
        invcnt+=merge1(a,temp,l,m+1,r);
    }
    return invcnt;
}
int cnt(int a[],int n)
{
    int *temp=(int*)malloc(sizeof(int)*(n+1));
    return ms(a,temp,0,n-1);
}
int main()
{
    int n,a[1000],i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<cnt(a,n);
    return 0;
}