#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> q;
    int n,k,i,a[1000];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<k;i++)
    {
        while(!q.empty()&&a[i]>=a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<" ";
        while(!q.empty()&&q.front()<=i-k)
            q.pop_front();
        while(!q.empty()&&a[q.back()]<=a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()];
    return 0;
}