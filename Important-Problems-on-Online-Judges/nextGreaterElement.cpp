#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[100];
    map<int,int> m;
    stack<int> s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;)
    {
        if(s.empty()||a[i]<=s.top())
        {
            s.push(a[i]);
            i++;
        }
        else
        {
            m[s.top()]=a[i];
            s.pop();
        }
    }
    while(!s.empty())
    {
        m[s.top()]=-1;
        s.pop();
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<m[a[i]]<<"\n";
    }
    return 0;
}