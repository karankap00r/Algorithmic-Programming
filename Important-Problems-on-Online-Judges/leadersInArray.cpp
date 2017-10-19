#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1000],i,mx;
    mx=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]>mx)
        {
            mx=a[i];
            cout<<i<<" "<<a[i]<<"\n";
        }
    }
    return 0;
}