// DFS,BFS,Toposort Template

#include<bits/stdc++.h>
using namespace std;
#define ll long long
//1 based indexing
vector <ll> adj[1000005];
bool visited[1000005]; //Initially all nodes are unvisited
stack<int> s;
void Initialize()
{
    ll i;
    for(i=0;i<1000005;i++)
    {
        visited[i]=false;
    }
}
void dfs(ll i)                  // to convert into toposort instead of printing i push in stack after visiting all neighbours and pop out to visit in topo-order
{
    visited[i]=true;
    cout<<i<<" ";
    ll j;
    for(j=0;j<adj[i].size();j++)
        if(!visited[adj[i][j]])
            dfs(adj[i][j]);
}
void toposort(ll i)
{
    visited[i]=true;
    for(ll j=0;j<adj[i].size();j++)
        if(!visited[adj[i][j]])
            toposort(adj[i][j]);
    s.push(i);
}
void bfs(ll i)
{
    queue<ll> q;
    q.push(i);
    visited[i]=true;
    ll node,j;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        cout<<node<<" ";
        for(j=0;j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                q.push(adj[node][j]);
                visited[adj[node][j]]=true;
            }
        }
    }
}
int main()
{
    ll n,m,i,j;
    //n : no. of nodes
    //m : no. of pairs of connected nodes
    cin>>n>>m;
    while(m--)
    {
        cin>>i>>j;
        adj[i].push_back(j);                                        //considering adirected graph
        adj[j].push_back(i);
    }
    /* DFS */
    //The following 3 lines of code assume that the graph is a connected one
    cout<<"Enter the node from which you wish to start the DFS:\n";
    cin>>i;
    dfs(i);
    //Comment out the following code to find the no. of connected components in a graph if it is not a connected one
    /*
    ll connected_comp=0;
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            connected_comp++;
        }
    }
    cout<<"Connected components = "<<connected_comp<<"\n";
    */
    //Comment out the following code to find the topological order of a graph if it is a DAG
    /*
    for(i=1;i<=N;i++)
        if(!visited[i])
            toposort(i);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    */
    /* DFS Over */
    Initialize();
    cout<<"\n";
    /* BFS */
    cout<<"Enter the node from which you wish to start the BFS:\n";
    cin>>i;
    bfs(i);
    /*BFS Over */
    return 0;
}
