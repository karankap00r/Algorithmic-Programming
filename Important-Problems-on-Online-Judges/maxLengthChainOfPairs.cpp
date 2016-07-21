#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<pair<ll,ll> > v;
    ll n,x,y;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    ll *mcl=(ll*)malloc(sizeof(ll)*(v.size()+1));
    for(ll i=0;i<v.size();i++)
    {
        mcl[i]=1;
    }
    ll ans=-1;
    for(ll i=0;i<v.size();i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(v[j].second<v[i].first&&mcl[j]+1>mcl[i])
            {
                mcl[i]=mcl[j]+1;
            }
        }
        ans=max(ans,mcl[i]);
    }
    cout<<ans;
    return 0;
}