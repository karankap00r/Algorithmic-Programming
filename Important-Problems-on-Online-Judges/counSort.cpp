#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    char output[1000];
    cin>>s;
    int cnt[256];
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<s.length();i++)
    {
        cnt[s[i]]++;
    }
    for(i=1;i<256;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(i=s.length()-1;i>=0;i--)
    {
        output[cnt[s[i]]-1]=s[i];
        cnt[s[i]]--;
    }
    for(i=0;i<s.length();i++)
    {
        s[i]=output[i];
    }
    cout<<s;
    return 0;
}