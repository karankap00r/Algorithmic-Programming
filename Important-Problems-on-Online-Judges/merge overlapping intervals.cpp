#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first<b.first;
}
int main()
{
    vector<pair<int,int> > v;
    int n,i,x,y,s,e;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),comp);
    s=v[0].first;
    e=v[0].second;
    for(i=1;i<n;i++)
    {
        if(v[i].first>e)
        {
            cout<<s<<" "<<e<<"\n";
            s=v[i].first;
            e=v[i].second;
        }
        else if(v[i].first>=s&&v[i].first<=e)
        {
            e=max(e,v[i].second);
        }
    }
    cout<<s<<" "<<e<<"\n";
    return 0;
}