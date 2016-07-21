#include<bits/stdc++.h>
using namespace std;
int maxCrossingSum(int a[],int l,int m,int r)
{
    int i;
    int sum=0;
    int left_sum=INT_MIN;
    for(i=m;i>=l;i--)
    {
        sum=sum+a[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }
    sum=0;
    int ryt_sum=INT_MIN;
    for(i=m+1;i<=r;i++)
    {
        sum=sum+a[i];
        if(sum>ryt_sum)
        {
            ryt_sum=sum;
        }
    }
    return left_sum+ryt_sum;
}
int maxSubarraySum(int a[],int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return a[l];
    int m=(l+r)/2;
    return max(maxSubarraySum(a,l,m),max(maxSubarraySum(a,m+1,r),maxCrossingSum(a,l,m,r)));
}
int main()
{
    int n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxSubarraySum(a,0,n-1);
    return 0;
}