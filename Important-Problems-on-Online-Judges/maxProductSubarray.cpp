#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max_ending_here=1;
    int min_ending_here=1;
    int max_so_far=1;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            max_ending_here=max_ending_here*a[i];
            min_ending_here=min(min_ending_here*a[i],1);
        }
        else if(a[i]==0)
        {
            max_ending_here=1;
            min_ending_here=1;
        }
        else
        {
            int temp=max_ending_here;
            max_ending_here=max(min_ending_here*a[i],1);
            min_ending_here=temp*a[i];
        }
//        cout<<max_ending_here<<" "<<min_ending_here<<" "<<max_so_far<<"\n";
        max_so_far=max(max_so_far,max_ending_here);
    }
    cout<<max_so_far;
    return 0;
}