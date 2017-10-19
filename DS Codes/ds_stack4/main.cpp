//REVERSE A STRING USING STACK
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s1;
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    for(typeof(s.begin()) it=s.begin();it!=s.end();it++)
    {
        s1.push(*it);
    }
    cout<<"\nReversed String : ";
    while(!s1.empty())
    {
        char x=s1.top();
        cout<<x;
        s1.pop();
    }
    s.clear();
    return 0;
}
