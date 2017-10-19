#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cur_max=0,max_so_far=-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            cur_max++;
            max_so_far=max(cur_max,max_so_far);
        }
        else
        {
            cur_max--;
            if(cur_max<0)
            {
                cout<<"Unbalanced";
                return 0;
            }
        }
    }
    if(cur_max!=0)
    {
        cout<<"Unbalanced";
    }
    else
    {
        cout<<max_so_far;
    }
    return 0;
}