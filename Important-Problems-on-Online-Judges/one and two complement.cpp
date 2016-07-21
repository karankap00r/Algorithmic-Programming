#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ones,twos;
    cin>>s;     //binary string
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            ones+='0';
        }
        else
        {
            ones+='1';
        }
    }
    cout<<ones<<"\n";
    int i=ones.length()-1;
    twos=ones;
    while(i>=0&&twos[i]=='1')
    {
        twos[i]='0';
        i--;
    }
    if(i>=0)
    {
        twos[i]='1';
    }
    cout<<twos;
    return 0;
}