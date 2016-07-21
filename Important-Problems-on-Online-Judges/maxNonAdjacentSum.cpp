#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,max_incl,max_excl,temp,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    max_incl=a[0];
    max_excl=0;
    for(i=1;i<n;i++)
    {
        temp=max_excl;
        max_excl=max(max_incl,max_excl);
        max_incl=max(max_incl,temp+a[i]);
    }
    cout<<max(max_incl,max_excl);
    return 0;
}