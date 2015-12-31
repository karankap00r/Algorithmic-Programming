bool visited[110];      //for unexplored nodes
bool visited2[110];     //for marking nodes gray and black detecting back edge
bool ans;
void dfs(ll i)
{
    if(visited2[i])
    {
        ans=true;       //signifies cycle
        return;
    }
    visited2[i]=true;
    for(ll j=0;j<adj[i].size();j++)
    {
        if(visited2[adj[i][j]])
            ans=true;
        if(!visited[adj[i][j]])
        {
            visited[adj[i][j]]=true;
            dfs(adj[i][j]);
        }
    }
    visited2[i]=false;
}
bool check_cycle()
{
    for(ll i=0;i<26;i++)
    {
        visited[i]=false;
    }
    for(ll i=0;i<26;i++)
    {
        dfs(i);
        if(ans==true)
            return true;
    }
    return false;
}
