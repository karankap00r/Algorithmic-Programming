#include<bits/stdc++.h>
using namespace std;
int findMax(int a[],int n)
{
    int i,mx=-1,ind=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>mx)
        {
            mx=a[i];
            ind=i;
        }
    }
    return ind;
}
void flip(int a[],int n)
{
    int l=0;
    int r=n;
    while(l<r)
    {
        swap(a[l],a[r]);
        l++;
        r--;
    }
}
int main()
{
    int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=n;i>=1;i--)
    {
        int mi=findMax(a,i);
        flip(a,mi);
        flip(a,i-1);
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}