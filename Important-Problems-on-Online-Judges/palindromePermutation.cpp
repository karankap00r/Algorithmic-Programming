#include<bits/stdc++.h>
using namespace std;
map<char,ll> f;
void palindromePermutation(string s,int pos)
{
    if(pos)
}
int main()
{
    string s;
    cin>>s;
    if(!isPalin(s))
    {
        cout<<"None";
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        f[s[i]]++;
    }
    s.clear();
    for(char ch='a';ch<='z';ch++)
    {
        if(f[ch]%2==0)
            f[ch]/=2;
        else
        {
            if(f[ch]>1)
                f[ch]/=2;
            oddc=ch;
        }
        for(j=0;j<f[ch];j++)
        {
            s+=ch;
        }
    }
    palindromePermutation(s,0);
    return 0;
}