#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],l,m,h;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l=0;
    m=0;
    h=n-1;
    while(m<=h)
    {
        switch(a[m])
        {
        case 0:
            {
                swap(a[l],a[m]);
                l++;
                m++;
                break;
            }
        case 1:
            {
                m++;
                break;
            }
        case 2:
            {
                swap(a[m],a[h]);
                h--;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}