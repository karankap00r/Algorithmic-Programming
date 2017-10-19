//UFDS over a range
//LINK : http://codeforces.com/problemset/problem/566/D

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll *id, cnt, *sz, *last;
map<ll,ll> mp;  //use this map to map indexes with data.
void init(ll N)
{
    cnt = N;
	id = new ll[N+1];
	sz = new ll[N+1];
    last = new ll[N+1];
    for(ll i=1; i<=N; i++)
    {
        id[i] = i;
	    sz[i] = 1;
	    last[i]=i+1;
	}
}
ll find(ll p)
{
    if(id[p]==p)
        return p;
    return (id[p]=find(id[p]));
}
void mergedsu(ll x, ll y)
{
    ll i = find(x);
    ll j = find(y);
    if (i == j)
        return;
    if(sz[i]>sz[j])
        swap(i,j);
    id[i]=j;
    sz[j]+=sz[i];
    cnt--;
}
void mergeseg(ll x,ll y)        //O(n) over all queries
{
    ll l=x,t;
    while(l<y)                  //this loop does merging over a segment thats why we do
    {
        mergedsu(l,l+1);        //merge cur and next :)
        t=l;
        l=last[l];              //set l = last member of set
        last[t]=y;              //set last of every merged element to the last element of the range.
    }
}
void destroy()
{
    delete []id;
	delete []sz;
}
int main()
{
    ll n,q,type,x,y;
    cin>>n>>q;
    init(n);
    while(q--)
    {
        cin>>type>>x>>y;
        if(type==1)
        {
            mergedsu(x,y);
        }
        else if(type==2)
        {
            mergeseg(x,y);
        }
        else
        {
            if(find(x)==find(y))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}

