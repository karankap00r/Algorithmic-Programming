//Dijkstra Algorithm Template 

//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF LONG_LONG_MAX //Infinity
const long long sz=10001; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<long long,long long> > a[sz]; //Adjacency list
long long dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not
//Custom Comparator for Determining priority for priority queue (shortest edge comes first)
class prioritize{public: bool operator ()(pair<long long, long long>&p1 ,pair<long long, long long>&p2){return p1.second>p2.second;}};
priority_queue<pair<long long,long long> ,vector<pair<long long,long long> >, prioritize> pq; //Priority queue to store vertex,weight pairs
void Dijkstra(long long source, long long n) //Algorithm for SSSP
{
    for(long long i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
    while(!pq.empty())
    {
        pair<long long, long long> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        long long cv=curr.first,cw=curr.second; //'cw' the final shortest distance for this vertex
        if(vis[cv]) //If the vertex is already visited, no polong long in exploring adjacent vertices
            continue;
        vis[cv]=true;
        for(long long i=0;i<a[cv].size();i++) //Iterating through all adjacent vertices
            if(!vis[a[cv][i].first] && a[cv][i].second+cw<dis[a[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw))); //Set the new distance and add to priority queue
    }
}
int main() //Driver Function for Dijkstra SSSP
{
    long long n,m,x,y,w;//Number of vertices and edges
    //cout<<"Enter number of vertices and edges in the graph\n";
    cin>>n>>m;
    for(long long i=0;i<m;i++) //Building Graph
    {
        cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
    long long source;
    cin>>source;
    Dijkstra(source,n);//SSSP from source (Also passing number of vertices as parameter)
    cout<<"Source is: "<<source<<". The shortest distance to every other vertex from here is: \n";
    for(long long i=1;i<=n;i++)//Prlong longing final shortest distances from source
    {
        cout<<"Vertex: "<<i<<" , Distance: ";
        dis[i]!=INF? cout<<dis[i]<<"\n" : cout<<"-1\n";
    }
    return 0;
}
