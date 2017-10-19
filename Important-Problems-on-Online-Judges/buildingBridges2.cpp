#include <bits/stdc++.h>
using namespace std;

void printBridges(pair<int,int> p[],int prev[],int idx)
{
    if(prev[idx]==-1)
    {
        cout<<"("<<p[idx].first<<","<<p[idx].second<<") ";
        return;
    }

    printBridges(p,prev,prev[idx]);
    cout<<"("<<p[idx].first<<","<<p[idx].second<<") ";
}

int getMaxBridges(pair<int,int> p[],int n)
{
    sort(p,p+n);

    int L[n],prev[n],maxi,mx=0;

    for(int i=0;i<n;i++)
    {
        L[i]=1;
        prev[i]=-1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[i].second>p[j].second&&L[j]+1>L[i])
            {
                L[i]=L[j]+1;
                prev[i]=j;
            }
        }
        if(L[i]>mx)
        {
            mx=L[i];
            maxi=i;
        }
    }

    cout<<"The Bridges to be constructed are: "<<endl;
    printBridges(p,prev,maxi);
    cout<<endl;

    return mx;
}

int main()
{
    pair<int,int> p[]={{5,5},{7,6},{6,2},{8,7},{2,1},{4,3},{1,8},{3,4}};
    int n=sizeof(p)/sizeof(p[0]);
    cout<<"Max number of Bridges are: "<<getMaxBridges(p,n);
    return 0;
}