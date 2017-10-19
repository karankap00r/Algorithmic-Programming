#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int temp,i,x,carry;
    vector<int> u,v;
    string tempstr(abs(a.length()-b.length()),'0');
    cin>>a>>b;
    if(a.length()>b.length())
    {
        b=b+tempstr;
    }
    else if(b.length()>a.length())
    {
        a=a+tempstr;
    }
    istringstream is1(a),is2(b);
    while(is1>>temp)
    {
        u.push_back(temp);
    }
    while(is2>>temp)
    {
        v.push_back(temp);
    }
    reverse(u.begin(),u.end());
    reverse(v.begin(),v.end());
    carry=0;
    for(i=0;i<u.size();++i)
    {
        x=u[i]+v[i]+carry;
        carry=(x/10);
        u[i]=x%10;
    }
    while(carry)
    {
        u.push_back(carry%10);
        carry=carry/10;
    }
    for(i=u.size()-1;i>=0;--i)
    {
        cout<<u[i];
    }
    return 0;
}
// O(n) time complexity
