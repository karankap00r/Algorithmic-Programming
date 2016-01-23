//implementation of problem fibosum by matrix exponentiation (SPOJ)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<vector<ll> > v(3,vector<ll>(3,1));
ll fibo(ll n)
{
    vector<vector<ll> > x(3,vector<ll>(3,1));
    vector<vector<ll> > y(3,vector<ll>(3,1));
    vector<vector<ll> > z(3,vector<ll>(3,0));   //temporary
    ll i,j,k;
    y[0][0]=v[0][0];
    y[0][1]=v[0][1];
    y[0][2]=v[0][2];
    y[1][0]=v[1][0];
    y[1][1]=v[1][1];
    y[1][2]=v[1][2];
    y[2][0]=v[2][0];
    y[2][1]=v[2][1];
    y[2][2]=v[2][2];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            x[i][j]=1;
        }
    }
    while(n>0)
    {
        if(n&1)                             //x=x*y
        {
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    z[i][j]=0;
                    for(k=0;k<3;k++)
                    {
                        z[i][j]=((z[i][j])%mod+(((x[i][k])%mod)*((y[k][j])%mod)%mod))%mod;
                    }
                }
            }
            x[0][0]=z[0][0];
            x[0][1]=z[0][1];
            x[0][2]=z[0][2];
            x[1][0]=z[1][0];
            x[1][1]=z[1][1];
            x[1][2]=z[1][2];
            x[2][0]=z[2][0];
            x[2][1]=z[2][1];
            x[2][2]=z[2][2];
        }
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    z[i][j]=0;
                    for(k=0;k<3;k++)
                    {
                        z[i][j]=((z[i][j])%mod+(((y[i][k])%mod)*((y[k][j])%mod))%mod)%mod;
                    }
                }
            }
            y[0][0]=z[0][0];
            y[0][1]=z[0][1];
            y[0][2]=z[0][2];
            y[1][0]=z[1][0];
            y[1][1]=z[1][1];
            y[1][2]=z[1][2];
            y[2][0]=z[2][0];
            y[2][1]=z[2][1];
            y[2][2]=z[2][2];
            n=n/2;
    }
    return x[0][0];
}
int main()
{
    ll answer,t,m,n,i,j;
    v[1][1]=0;
    v[1][2]=0;
    v[2][0]=0;
    v[2][1]=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<((fibo(m)%mod)-(fibo(n-1)%mod)+mod)%mod<<"\n";
    }
    return 0;
}
