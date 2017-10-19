//implementation of problem fibonacci by matrix exponentiation 

//O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 2000000;
const ll MOD=1000000007;
ll id[MAX],a[1002][1002];
vector < pair < ll, pair<ll,ll> > > v;
void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);
/* function that returns nth Fibonacci number */
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0]%MOD;
}
/* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  ((F[0][0]%MOD*M[0][0]%MOD)%MOD + (F[0][1]%MOD*M[1][0]%MOD)%MOD)%MOD;
  ll y =  ((F[0][0]%MOD*M[0][1]%MOD)%MOD + (F[0][1]%MOD*M[1][1]%MOD)%MOD)%MOD;
  ll z =  ((F[1][0]%MOD*M[0][0]%MOD)%MOD + (F[1][1]%MOD*M[1][0]%MOD)%MOD)%MOD;
  ll w =  ((F[1][0]%MOD*M[0][1]%MOD)%MOD + (F[1][1]%MOD*M[1][1]%MOD)%MOD)%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
int main()
{
    cout<<fib(10);
    return 0;
}
