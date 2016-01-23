//Segment Tree Template

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> tree,A,lazy;
void build(long long node,long long start,long long end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node]=A[start];
    }
    else
    {
        long long int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node+1, start, mid);
        // Recurse on the right child
        build(2*node+2, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}
void update(long long node,long long start,long long end,long long idx,long long val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node]+=val;
    }
    else
    {
        long long int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node+1, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+2, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}
int query(long long int node,long long int start,long long int end,long long int l,long long int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    long long int mid = (start + end) / 2;
    long long int p1 = query(2*node+1, start, mid, l, r);
    long long int p2 = query(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}

void updateRange(long long int node,long long int start,long long int end,long long int l,long long int r,long long int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
            lazy[node*2+2] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    long long int mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);        // Updating left child
    updateRange(node*2+2, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2+1] + tree[node*2+2];        // Updating root with max value
}

long long int queryRange(long long int node,long long int start,long long int end,long long int l,long long int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];         // Mark child as lazy
            lazy[node*2+2] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    long long int mid = (start + end) / 2;
    long long int p1 = queryRange(node*2+1, start, mid, l, r);         // Query left child
    long long int p2 = queryRange(node*2+2, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
long long int nextPowerOf2(long long int n)
{
    long long count = 0;
    //First n in the below condition is for the case where n is 0
    if (n && !(n&(n-1)))
        return n;
    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }
    return 1<<count;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    ll n,i,x,tree_size;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    tree_size=2*nextPowerOf2(n)-1;
    tree.resize(tree_size+1);
    lazy.resize(tree_size+1,0);

    build(0,0,n-1);
    cout<<"Sum of 1-3 : "<<queryRange(0,0,n-1,0,2)<<"\n";
    updateRange(0,0,n-1,0,2,1);
    cout<<"Sum of 1-3 : "<<queryRange(0,0,n-1,0,2)<<"\n";
    return 0;
}



