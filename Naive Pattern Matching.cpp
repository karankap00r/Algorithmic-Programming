#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string a,b;
    ll i,j;
    bool n_ex=true;
    cin>>a>>b;
    for(i=0;i<a.length();i++)
    {
        for(j=0;j<b.length();j++)
        {
            if(a[i+j]!=b[j])
            {
                break;
            }
        }
        if(j==b.length())
        {
            n_ex=false;
            cout<<"Found at "<<i<<" position\n";
        }
    }
    if(n_ex)
    {
        cout<<"No match found !";
    }
    return 0;
}
