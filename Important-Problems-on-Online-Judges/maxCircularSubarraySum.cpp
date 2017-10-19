#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n)
{
    int cur_max=a[0];
    int max_so_far=a[0];
    for(int i=1;i<n;i++)
    {
        cur_max=max(cur_max+a[i],a[i]);
        max_so_far=max(max_so_far,cur_max);
    }
    return max_so_far;
}
int main()
{
    int n,i,a[100],normal_sum,circ_sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    normal_sum=kadane(a,n);
    for(i=0;i<n;i++)
    {
        circ_sum+=a[i];
        a[i]=-a[i];
    }
    circ_sum+=kadane(a,n);
    cout<<max(normal_sum,circ_sum);
    return 0;
}