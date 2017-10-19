#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000009],b[1000009];
int main()
{
    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    ll cnt=0;
    for(i=0;i<n;i++)
    {   
        if(a[i]!=b[i])
        {
            cnt++;
        }
    }
    if(cnt<=2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}