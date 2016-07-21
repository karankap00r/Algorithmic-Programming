#include<bits/stdc++.h>
using namespace std;
struct item
{
    int sum;
    int i;
    int j;
};
int comp(const void* a,const void* b)
{
    return (*(item*)(a)).sum-(*(item*)(b)).sum;
}
item aux[1000];
int main()
{
    int n,i,a[1000],sum,j,k,l,cnt,ind;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>sum;
    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            aux[cnt].sum=a[i]+a[j];
            aux[cnt].i=i;
            aux[cnt].j=j;
            cnt++;
        }
    }
    qsort(aux,cnt,sizeof(aux[0]),comp);
    i=0;
    j=cnt-1;
    while(i<j)
    {
        if(aux[i].sum+aux[j].sum<sum)
        {
            i++;
        }
        else if(aux[i].sum+aux[j].sum>sum)
        {
            j--;
        }
        else
        {
            if(aux[i].i==aux[j].i||aux[i].j==aux[j].i||aux[i].i==aux[j].j||aux[i].j==aux[j].j)
            {
                i++;
                j--;
                continue;
            }
            else
            {
                cout<<a[aux[i].i]<<" "<<a[aux[i].j]<<" "<<a[aux[j].i]<<" "<<a[aux[j].j]<<"\n";
                i++;
                j--;
            }
        }
    }
    return 0;
}