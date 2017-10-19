#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="";
    int n,temp;
    cin>>n;
    while(n>0)
    {
        temp=n%26;
        if(temp==0)
        {
            s='z'+s;
            n=n/26-1;
        }
        else
        {
            s=(char)('a'+temp-1)+s;
            n=n/26;
        }
    }
    cout<<s;
    return 0;
}