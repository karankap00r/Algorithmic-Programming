#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c,i,j,l,t;
    char a[100][100];
    cin>>r>>c;
    ll m=r;
    ll n=c;
    l=0;
    t=0;
    char ch='X';
    while(l<c&&t<r)
    {
        for(i=l;i<c;i++)
        {
            a[t][i]=ch;
        }
        t++;
        for(i=t;i<r;i++)
        {
            a[i][c-1]=ch;
        }
        c--;
        if(t<r)
        {
            for(i=c-1;i>=l;i--)
            {
                a[r-1][i]=ch;
            }
            r--;
        }
        if(l<c)
        {
            for(i=r-1;i>=t;i--)
            {
                a[i][l]=ch;
            }
            l++;
        }
        if(ch=='X')
        {
            ch='O';
        }
        else
        {
            ch='X';
        }
    }
    r=m;
    c=n;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}