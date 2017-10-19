#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define FILE_IO freopen("input.in","r",stdin);freopen("output.txt","w",stdout);
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    char ans;
    int cnt[1000];
    char str[1000];
    int i,mx;
    cin>>str;
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<strlen(str);i++)
    {
        cnt[str[i]]++;
    }
    mx=-1;
    for(i=0;i<strlen(str);i++)
    {
        if(cnt[str[i]]>mx)
        {
            ans=str[i];
            mx=cnt[str[i]];
        }
    }
    cout<<ans;
    return 0;
}