#include<bits/stdc++.h>
using namespace std;
bool ismatchingbrace(char ch1,char ch2)
{
    if(ch1=='('&&ch2==')')
        return true;
    else if(ch1=='{'&&ch2=='}')
        return true;
    else if(ch1=='['&&ch2==']')
        return true;
    else return false;
}
int main()
{
    char s[100];
    stack<char> s1;
    bool valid=true;
    int i;
    cout<<"Enter the string : ";
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            s1.push(s[i]);
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(s1.empty()==true)
            {
                valid=false;
                break;
            }
            else if(ismatchingbrace(s1.top(),s[i])==false)
            {
                valid=false;
                break;
            }
            else
            {
                s1.pop();
            }
        }
    }
    if(s1.empty()==false)
    {
        valid=false;
    }
    if(valid==true)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
    return 0;
}
