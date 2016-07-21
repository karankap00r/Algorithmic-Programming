#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[100],b[100],cur_petrol;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int s=0;
    int e=1;
    cur_petrol=a[0]-b[0];
    while(s!=e||cur_petrol<0)
    {
        while(s!=e&&cur_petrol<0)
        {
            cur_petrol-=(a[s]-b[s]);
            s=(s+1)%n;
            if(s==0)
            {
                cout<<"not found";
                return 0;
            }
        }
        cur_petrol+=(a[e]-b[e]);
        e=(e+1)%n;
    }
    cout<<s;
    return 0;
}