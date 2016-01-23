//Matrix exponentiation + MST
// Problem Link : https://www.hackerearth.com/problem/algorithm/proving-your-intelligence-to-your-girlfriend-1/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll grid[1009][1009];
#define mod 1000000007
vector<vector<ll> > v(2,vector<ll>(2,1));
ll fibo(ll n)
{
    vector<vector<ll> > x(2,vector<ll>(2,1));
    vector<vector<ll> > y(2,vector<ll>(2,1));
    vector<vector<ll> > z(2,vector<ll>(2,0));   //temporary
    ll i,j,k;
    y[0][0]=v[0][0];
    y[0][1]=v[0][1];
    //y[0][2]=v[0][2];
    y[1][0]=v[1][0];
    y[1][1]=v[1][1];
    //y[1][2]=v[1][2];
    //y[2][0]=v[2][0];
    //y[2][1]=v[2][1];
    //y[2][2]=v[2][2];
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            x[i][j]=1;
        }
    }
    while(n>0)
    {
        if(n&1)                             //x=x*y
        {
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                {
                    z[i][j]=0;
                    for(k=0;k<2;k++)
                    {
                        z[i][j]=((z[i][j])%mod+(((x[i][k])%mod)*((y[k][j])%mod)%mod))%mod;
                    }
                }
            }
            x[0][0]=z[0][0];
            x[0][1]=z[0][1];
            //x[0][2]=z[0][2];
            x[1][0]=z[1][0];
            x[1][1]=z[1][1];
            //x[1][2]=z[1][2];
            //x[2][0]=z[2][0];
            //x[2][1]=z[2][1];
            //x[2][2]=z[2][2];
        }
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                {
                    z[i][j]=0;
                    for(k=0;k<2;k++)
                    {
                        z[i][j]=((z[i][j])%mod+(((y[i][k])%mod)*((y[k][j])%mod))%mod)%mod;
                    }
                }
            }
            y[0][0]=z[0][0];
            y[0][1]=z[0][1];
            //y[0][2]=z[0][2];
            y[1][0]=z[1][0];
            y[1][1]=z[1][1];
            //y[1][2]=z[1][2];
            //y[2][0]=z[2][0];
            //y[2][1]=z[2][1];
            //y[2][2]=z[2][2];
            n=n/2;
    }
    return x[0][0];
}
ll res(ll x)
{
    if(x==1)
    {
        return 1;
    }
    return fibo(x-2);
}
ll *id, cnt, *sz;
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
const ll MAX = 1000099;
vector<pair <long long, pair<ll, ll> > > p;
ll nodes,edges;
long long kruskal()
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 1;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(find(x) != find(y))
        {
            minimumCost += cost;
            merge(x, y);
        }
    }
    return minimumCost;
}
ll n;
ll mp(ll x,ll y)
{
    return n*(x-1)+y;
}
ll x,y,wt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll minimumCost,t,m,i,j,k1,k2,k3,k4,temp1,temp2;
    v[0][0]=1;
    v[0][1]=1;
    v[1][0]=1;
    v[1][1]=0;
    cin>>n>>k1>>k2>>k3>>k4;
    init(n*n+1);
    ll num=1;
    ll ans1=res(k1)%mod;
    ll ans2=res(k2)%mod;
    //cout<<ans1<<" "<<ans2<<"\n";
    ll next_ans1=res(k1+1)%mod;
    ll next_ans2=res(k2+1)%mod;
    //cout<<next_ans1<<" "<<next_ans2<<"\n";
    p.push_back(make_pair(0,make_pair(0,0)));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
        {
            temp1=mp(i,j);
            temp2=mp(i,j+1);
            x=temp1;
            y=temp2;
            wt=(ans1%mod+ans2%mod)%mod;
            p.push_back(make_pair(wt, make_pair(x, y)));
            //cout<<wt[num]<<"\n";
            ll z1=(ans1%mod+next_ans1%mod)%mod;
            ll z2=(ans2%mod+next_ans2%mod)%mod;
            ans1=next_ans1%mod;
            ans2=next_ans2%mod;
            next_ans1=z1%mod;
            next_ans2=z2%mod;
            //cout<<ans1<<" "<<ans2<<"\n";
            num++;
        }
    }
    ans1=res(k3)%mod;
    ans2=res(k4)%mod;
    //cout<<ans1<<" "<<ans2<<"\n";
    next_ans1=res(k3+1)%mod;
    next_ans2=res(k4+1)%mod;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
        {
            temp1=mp(j,i);
            temp2=mp(j+1,i);
            x=temp1;
            y=temp2;
            wt=(ans1%mod+ans2%mod)%mod;
            p.push_back(make_pair(wt, make_pair(x, y)));
            //cout<<wt[num]<<"\n";
            ll z1=(ans1%mod+next_ans1%mod)%mod;
            ll z2=(ans2%mod+next_ans2%mod)%mod;
            ans1=next_ans1%mod;
            ans2=next_ans2%mod;
            next_ans1=z1%mod;
            next_ans2=z2%mod;
            num++;
        }
    }
    edges=num;
    sort(p.begin()+1,p.end());
    minimumCost = kruskal();
    cout << minimumCost << endl;
    destroy();
    return 0;
}
