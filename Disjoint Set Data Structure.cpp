#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll *id, cnt, *sz;
map<ll,ll> mp;  //use this map to map indexes with data.
void init(ll N)
{
    cnt = N;
	id = new ll[N+1];
	sz = new ll[N+1];
    for(ll i=1; i<=N; i++)
    {
        id[i] = i;
	    sz[i] = 1;
	}
}
ll find(ll p)
{
    ll root = p;
    while (root != id[root])
        root = id[root];
    while (p != root) {
        ll newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}
// Replace sets containing x and y with their union.
void merge(ll x, ll y)
{
    ll i = find(x);
    ll j = find(y);
    if (i == j) return;
    // make smaller root point to larger one
    if(sz[i]<sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
    cnt--;
}
// Are objects x and y in the same set?
bool connected(ll x, ll y)
{
    return find(x) == find(y);
}
// Return the number of disjoint sets.
ll count()
{
    return cnt;
}
void destroy()
{
    delete []id;
	delete []sz;
}
int main()
{
    ll n,i,data[100],x,y;
    cout<<"Enter the number of indexes : ";
    cin>>n;
    init(n);
    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<id[i]<<"\n";
    }
    merge(1,4);
    merge(2,5);
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<id[i]<<"\n";
    }
    destroy();
    cout<<"Enter the number of elements : ";
    cin>>n;
    init(n);
    cout<<"Please enter the elements : \n\n";
    for(i=1;i<=n;i++)
    {
        cin>>data[i];
        mp[data[i]]=i;
    }
    cout<<"Enter elements to merge : ";
    cin>>x>>y;
    cout<<"Representatives of set before merging are : ";
    cout<<find(mp[x])<<" "<<find(mp[y])<<"\n";
    merge(mp[x],mp[y]);
    cout<<"Representatives of set after merging are : ";
    cout<<find(mp[x])<<" "<<find(mp[y])<<"\n";
    return 0;
}
