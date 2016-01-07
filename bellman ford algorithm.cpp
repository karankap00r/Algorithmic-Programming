#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
struct node
{
    ll x,y,w;
    node(ll a,ll b,ll c)
    {
        x=a;
        y=b;
        w=c;
    }
};
ll neg_cycle;
ll n;
ll dis[100];
vector<node> v;
void bellman_ford(long long source)
{
    ll i,j,first,second,weight;
    for(i=1;i<=n;i++)
    {
        dis[i]=LONG_LONG_MAX;
    }
    dis[source]=0;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<v.size();j++)
        {
            first=v[j].x;
            second=v[j].y;
            weight=v[j].w;
            if(dis[second]>dis[first]+weight)
            {
                dis[second]=dis[first]+weight;
            }
        }
    }
    for(i=0;i<v.size();i++)
    {
        first=v[i].x;
        second=v[i].y;
        weight=v[i].w;
        if(dis[second]>dis[first]+weight)
        {
            neg_cycle=1;
        }
    }
}
int main()
{
    ll m,i,x,y,w;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        v.push_back(node(x,y,w));
    }
    neg_cycle=0;
    bellman_ford(1);
    if(neg_cycle==1)
    {
        cout<<"Negative Cycle Found !\n";
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cout<<dis[i]<<" ";
        }
    }
    return 0;
}
