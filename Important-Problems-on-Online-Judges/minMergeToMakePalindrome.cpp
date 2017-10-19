#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,a[1000],j,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    i=0;
    j=n-1;
    ans=0;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else if(a[i]>a[j])
        {
            j--;
            a[j]+=a[j+1];
            ans++;
        }
        else
        {
            i++;
            a[i]+=a[i-1];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}