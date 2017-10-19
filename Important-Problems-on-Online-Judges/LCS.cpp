#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100][100];
int lcs(char *s1,char *s2,int p1,int p2,int m,int n)
{
    if(p1>=m||p2>=n)
    {
        return 0;
    }
    if(dp[p1][p2]!=-1)
    {
        return dp[p1][p2];
    }
    if(s1[p1]==s2[p2])
    {
        return dp[p1][p2]=1+lcs(s1,s2,p1+1,p2+1,m,n);
    }
    return dp[p1][p2]=max(lcs(s1,s2,p1,p2+1,m,n),lcs(s1,s2,p1+1,p2,m,n));
}
void Print(char *s1,char *s2,int p1,int p2,int m,int n)
{
    if(p1==m||p2==n)
        return;
    if(s1[p1]==s2[p2])
    {
        cout<<s1[p1];
        Print(s1,s2,p1+1,p2+1,m,n);
    }
    else
    {
        if(lcs(s1,s2,p1,p2,m,n)==lcs(s1,s2,p1+1,p2,m,n))
        {
            Print(s1,s2,p1+1,p2,m,n);
        }
        else
        {
            Print(s1,s2,p1,p2+1,m,n);
        }
    }
}
ll lcsBU(char *s1,char *s2,int m,int n)
{
    int L[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                L[i][j]=1+L[i-1][j-1];
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    return L[m][n];
}
int main()
{
    int i,j;
    char *s1="ABCD";
    char *s2="AXBYCZD";
    int m=strlen(s1);
    int n=strlen(s2);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans=lcs(s1,s2,0,0,m,n);
    cout<<ans;
    Print(s1,s2,0,0,m,n);
    cout<<"\n";
    cout<<lcsBU(s1,s2,m,n);
    return 0;
}