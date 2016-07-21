#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> > v;
int main()
{
    ll n,i,x,y,e;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    e=v[0].second;
    ll cnt=0;
    for(i=1;i<n;i++)
    {
        if(v[i].second<e)
        {
            cnt++;
        }
        else
        {
            e=max(e,v[i].second);
        }
    }
    cout<<cnt;
    return 0;
}