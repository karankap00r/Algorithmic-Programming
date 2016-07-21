#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cur_sum,i,sum,j,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cur_sum=a[0];
    cin>>sum;
    i=0;
    j=0;
    while(i<=j&&j<=n-1)
    {
        //cout<<cur_sum<<" "<<i<<" "<<j<<"\n";
        if(cur_sum<sum)
        {
            j++;
            cur_sum+=a[j];
        }
        else if(cur_sum>sum)
        {
            cur_sum-=a[i];
            i++;
        }
        else
        {
            break;
        }
    }
    if(cur_sum==sum)
        cout<<i<<" "<<j;
    else
        cout<<"not found";
    return 0;
}