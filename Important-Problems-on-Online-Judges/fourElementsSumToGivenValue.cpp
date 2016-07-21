#include<bits/stdc++.h>
using namespace std;
int comp(const void* a,const void* b)
{
    return (*(int*)(a))-(*(int*)(b));
}
int main()
{
    int n,i,a[100],sum,j,k,l;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>sum;
    qsort(a,n,sizeof(a[0]),comp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            k=i+2;
            l=n-1;
            while(k<l)
            {
                if(a[i]+a[j]+a[k]+a[l]>sum)
                {
                    l--;
                }
                else if(a[i]+a[j]+a[k]+a[l]<sum)
                {
                    k++;
                }
                else
                {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}