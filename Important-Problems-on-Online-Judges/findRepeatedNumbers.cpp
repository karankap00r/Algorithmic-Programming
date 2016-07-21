#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],set_bit,y;
    cin>>n;
    int val=n-2;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x=a[0];
    for(i=1;i<n;i++)
    {
        x^=a[i];
    }
    for(i=1;i<=val;i++)
    {
        x^=i;
    }
    set_bit=x& ~(x-1);
    x=0;
    y=0;
    for(i=0;i<n;i++)
    {
        if(set_bit&a[i])
        {
            x=x^a[i];
        }
        else
        {
            y=y^a[i];
        }
    }
    for(i=1;i<=val;i++)
    {
        if(set_bit&i)
        {
            x=x^i;
        }
        else
        {
            y=y^i;
        }
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}