#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1000],i,ans,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ans=0;
    for(i=0;i+2<n;i++)
    {
        j=i+1;
        k=i+2;
        for(j=i+1;j+1<n;j++)
        {
            while(k<n&&a[k]<a[i]+a[j])
                k++;
            ans+=(k-j-1);
        }
    }
    cout<<ans;
    return 0;
}