#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],x,y,f,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x>>y;
    f=-1;
    s=-1;
    int mn=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            s=f;
            f=i;
            if(s!=-1&&a[f]!=a[s])
            {
                mn=min(mn,abs(s-f));
            }
        }
    }
    cout<<mn;
    return 0;
}