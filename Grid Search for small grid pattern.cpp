#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
ll M, N, R, C;
vector <string> g, pat;
vector<pair<ll,ll> > v;
bool present(ll x, ll y) 
{
    for(ll i = 0; i < (ll)R; ++i) 
    {
        for(ll j = 0; j < (ll)C; ++j) 
        {
            ll ii = i + x, jj = j + y;
            if(ii >= M || jj >= N)
                return false;
            else if(g[ii][jj] != pat[i][j])
                return false;
            else
                continue;
        }
    }
    return true;
}
int main()
{
ll t;
ll i,j;
cin >> t;
while(t--) 
{
    cin >> M >> N;
    g = vector <string> (M);
    for(i = 0; i < (ll)M; ++i) {
        cin >> g[i];
        }
    cin >> R >> C;
    pat = vector <string>(R);
    for(i = 0; i < (ll)R; ++i) {
        cin >> pat[i];
    }
    bool isPresent = false;
    for(i = 0; i < (ll)M; ++i) {
        for(j = 0; j < (ll)N; ++j) {
            isPresent = present(i, j);
            if(isPresent)
                break;
        }
        if(isPresent)
            v.push_back(mp(i,j));
    }
    if(v.size()==0)
    {
        cout<<"No match";
    }
    else
    {
        cout<<"Small grid found at : ";
        for(i=0;i<v.size();i++)
        {
            cout<<v[i].first<<","<<v[i].second<<"   ";
        }
    }
    v.clear();
}
return 0;
}
