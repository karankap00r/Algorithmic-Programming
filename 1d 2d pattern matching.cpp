//Template to match a string in a 2d grid of characters

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
//search in all 8 directions
vector<pair<ll,ll> > v;
bool ans;
ll r,c;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
string s;
char grid[100][100];
bool track(ll x,ll y)
{
    if(grid[x][y]!=s[0])
        return false;
    ll j;
    for(ll i=0;i<8;i++)
    {
        ll xd=x+dx[i];
        ll yd=y+dy[i];
        for(j=1;j<s.length();j++)
        {
            if(xd>r||xd<1||yd>c||yd<1)
            {
                break;
            }
            if(s[j]!=grid[xd][yd])
            {
                break;
            }
            xd+=dx[i];
            yd+=dy[i];
        }
        if(j==s.length())
        {
            ans=true;
            return true;
        }
    }
    return false;
}
void search()
{
    ll i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(track(i,j))
            {
                v.push_back(mp(i,j));
            }
        }
    }
}
int main()
{
    ll i,j;
    cin>>r>>c;
    for(i=1;i<=r;i++)
    {
        string temp;
        cin>>temp;
        for(j=1;j<=c;j++)
        {
            grid[i][j]=temp[j-1];
        }
    }
    cin>>s;
    ans=false;
    search();
    if(!ans)
    {
        cout<<"Pattern not found !";
    }
    else
    {
        cout<<"Pattern found at : "; 
        for(i=0;i<v.size();i++)
        {
            cout<<v[i].first<<","<<v[i].second<<"   ";
        }
    }
    return 0;
}
