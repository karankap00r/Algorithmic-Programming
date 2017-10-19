//INFIX TO POSTFIX CONVERSION
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100];
    stack <char> s1;
    int i;
    cout<<"Enter the infix expression : ";
    cin>>s;
    for(i=0;s[i]!='\0';i++)
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
            cout<<s[i];
        if(s[i]=='(')
        {
            s1.push(s[i]);
        }
        if(s[i]==')')
        {
            while(s1.top()!='(')
            {
                cout<<s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else
        {
            if(s1.empty())
            {
                s1.push(s[i]);
            }
            else if(s[i]=='*'||s[i]=='/')
                {
                    if(s1.top()=='/'||s1.top()=='*')
                    {
                        cout<<s1.top();
                        s1.pop();
                        s1.push(s[i]);
                    }
                    else if(s1.top()=='+'||s1.top()=='-')
                    {
                        s1.push(s[i]);
                    }
                }
                else if(s[i]=='+'||s[i]=='-')
                {
                    cout<<s1.top();
                    s1.pop();
                    s1.push(s[i]);
                }
        }
    }
    return 0;
}
