#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k,o,e,i;
    cin>>n>>k;
    o=1;
    e=n;
    for(i=1;i<=n;i++)
    {
        if(i<=k)
        {
            if(i&1)
            {
                cout<<o<<" ";
                o++;
            }
            else
            {
                cout<<e<<" ";
                e--;
            }
        }
        else
        {
            if(i&1==0)
            {
                while(i<=n)
                {
                    cout<<o++<<" ";
                    i++;
                }
                return 0;
            }
            else
            {
                while(i<=n)
                {
                    cout<<e--<<" ";
                    i++;
                }
                return 0;
            }
        }
    }
    return 0;
}