#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isSafe(ll row,ll col,ll **soln,ll n)
{
    ll i,j;
    for(i=0;i<col;i++)
    {
        if(soln[row][i])
        {
            return false;
        }
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(soln[i][j])
        {
            return false;
        }
    }
    for(i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(soln[i][j])
        {
            return false;
        }
    }
    return true;
}
bool calc(ll n,ll **soln,ll tot)
{
    if(n==tot)
    {
        return true;
    }
    else
    {
        ll i;
        for(i=0;i<tot;i++)
        {
            if(isSafe(i,n,soln,tot))
            {
                soln[i][n]=true;
                if(calc(n+1,soln,tot))
                {
                    return true;
                }
                soln[i][n]=false;
            }
        }
        return false;
    }
}
void solve(ll n)
{
    ll **soln=(ll**)malloc(sizeof(ll*)*(n+1));
    ll i;
    for(i=0;i<n;i++)
    {
        soln[i]=(ll*)malloc(sizeof(ll)*(n+1));
    }
    for(i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            soln[i][j]=0;
        }
    }
    bool ans=calc(0,soln,n);
    if(ans==false)
    {
        cout<<"Not arranged\n";
    }
    else
    {
        ll i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%2lld ",soln[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    solve(n);
    return 0;
}