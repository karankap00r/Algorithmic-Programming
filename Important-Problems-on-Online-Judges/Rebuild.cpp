//Problem Link : https://www.hackerearth.com/problem/algorithm/rebuild/description/
//Relation of degree with processing time in Kruskal is seen in this problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll *id, cnt, *sz;
ll in[1000000];
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
	    in[i]=0;
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
        id[i]=j;
        sz[j]+=sz[i];
    }
    else
    {
        id[j]=i;
        sz[i]+=sz[j];
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
//////////////////////////UFDS ends.
//////////////////////////MST code begins
const ll MAX = 1000000;
pair <long long, pair<ll, ll> > p[MAX];
ll nodes,edges;
long long kruskal(pair<long long, pair<ll, ll> > p[])
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(find(x) != find(y))
        {
            minimumCost += cost;
            in[x]++;
            in[y]++;
            merge(x, y);
        }
    }
    return minimumCost;
}
bool comp(const pair<ll,pair<ll,ll> > &a, const pair<ll,pair<ll,ll> > &b)
{
    if(a.first<b.first)
        return 1;
    else if(a.first>b.first)
        return 0;
    else if(a.first==b.first)
    {
        if(a.second.first>b.second.first)
            return 1;
        else if(a.second.first<b.second.first)
            return 0;
        else if(a.second.first==b.second.first)
        {
            if(a.second.second>b.second.second)
            {
                return 1;
            }
            else
                return 0;
        }
    }
}
int main()
{
    ll x, y;
    long long weight, cost, minimumCost,t,i;
    cin>>t;
    while(t--)
    {
        cin >> nodes >> edges;
        init(nodes);     //creating the sets
        for(i = 0;i < edges;++i)
        {
            cin >> x >> y >> weight;
            if(x>y)
                swap(x,y);
            p[i] = make_pair(weight, make_pair(x,y));   //(taken care in comp function) we do push -x,-y since nodes that are pushed first have a higher degree and nodes pushed later will have lower degree and since we need nodes with lower index to have a lower degree then we try to push -x,-y
        }
        sort(p, p + edges,comp);
        minimumCost = kruskal(p);
        cout << minimumCost << endl;
        for(i=1;i<=nodes;i++)
        {
            cout<<in[i]<<" ";
        }
        cout<<"\n";
        destroy();  //destroying the UFDS
    }
    return 0;
}
