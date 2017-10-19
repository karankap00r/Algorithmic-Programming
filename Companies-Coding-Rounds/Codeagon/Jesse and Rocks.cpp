#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100009];
int main()
{
    ll n,s,i,cnt;
    cin>>n>>s;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool flag=false;
    cnt=0;
    for(i=1;i<=n;i++)
    {
        if(s>=a[i])
        {
            cnt++;
        }
        else
        {
            if(!flag)
            {
                flag=true;
            }
            else
            {
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
