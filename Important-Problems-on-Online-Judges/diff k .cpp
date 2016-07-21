#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    i=0;
    int cnt=0;
    map<int,bool> hash;
    for(i=0;i<n;i++)
    {
        hash[a[i]]=true;
    }
    for(i=0;i<n;i++)
    {
        if(hash[a[i]-k])
        {
            cnt++;
        }
        if(hash[a[i]+k])
        {
            cnt++;
        }
        hash[a[i]]=false;
    }
    cout<<cnt;
    return 0;
}