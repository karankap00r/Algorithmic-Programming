//This problem is a mixture of MST and DP
//When we have alot of queries
//and we time out by calculating at that time
// we can do precomputation or DP to store the results on graph

//Problem : https://www.hackerearth.com/problem/algorithm/ioi-2050-2/description/

#include<bits/stdc++.h>
using namespace std;
#define ll int
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
pair <int, pair<ll, ll> > p[MAX];
vector<ll> adj[MAX];
ll temp[1009][1009],ans[1009][1009];
ll nodes,edges;
int kruskal(pair<int, pair<ll, ll> > p[])
{
    ll x, y;
    int cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(find(x) != find(y))
        {
            minimumCost += cost;
            adj[x].push_back(y);
            adj[y].push_back(x);
            temp[x][y]=cost;
            temp[y][x]=cost;
            merge(x, y);
        }
    }
    return minimumCost;
}
bool visited[1009];
void bfs(int nd, int src)
{
	queue<int> q;
	q.push(nd);
	while(!q.empty())
	{
		int id=q.front();
		q.pop();
		if(visited[id])
			continue;
		visited[id]=true;
		for(int i=0;i<adj[id].size();++i)
		{
			if(!visited[adj[id][i]])
			{
				if(src==adj[id][i])
					ans[src][adj[id][i]]=0;
				else
					ans[src][adj[id][i]]=(ans[src][id]+temp[id][adj[id][i]]);
				q.push(adj[id][i]);
			}
		}
	}
}int main()
{
    ll x, y;
    int weight, cost, minimumCost,t,q;
    cin>>t;
    ll count=0;
    while(t--)
    {
        count++;
        scanf("%d%d%d",&nodes,&edges,&q);
        init(nodes);     //creating the sets
        for(ll i = 0;i < edges;++i)
        {
            scanf("%d%d%d",&x,&y,&weight);
            p[i] = make_pair(weight, make_pair(x, y));
        }
        sort(p, p + edges);
        minimumCost = kruskal(p);
        printf("Case: %d\n",count);
        for(ll i=1;i<=nodes;i++)
        {
            memset(visited,0,sizeof(visited));
            bfs(i,i);
        }
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",ans[x][y]);
        }
        for(ll i=1;i<=nodes;i++)
        {
            adj[i].clear();
        }
        destroy();  //destroying the UFDS
    }
    return 0;
}

