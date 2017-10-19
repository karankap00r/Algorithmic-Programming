#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j;
    cin>>n>>k;
    int **dp=(int**)malloc(sizeof(int*)*(n+1));
    for(i=0;i<=n;i++)
    {
        dp[i]=(int*)malloc(sizeof(int)*(n+1));
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][k]<<"\n";
    int *table=(int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<=k;i++)
    {
        table[i]=0;
    }
    table[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=min(i,k);j>0;j--)
        {
            table[j]=table[j]+table[j-1];
        }
    }
    cout<<table[k];
    return 0;
}