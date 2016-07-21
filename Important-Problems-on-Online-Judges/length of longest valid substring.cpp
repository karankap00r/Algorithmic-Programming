#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    string str;
    cin>>str;
    s.push(-1);
    int ans=-1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            s.push(i);
        }
        else
        {
            s.pop();
            if(!s.empty())
            {
                ans=max(ans,i-s.top());
            }
            else
            {
                s.push(i);
            }
        }
    }
    cout<<ans;
    return 0;
}