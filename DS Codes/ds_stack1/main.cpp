#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],top,ch,i;
    char var;
    top=-1;
    while(1){
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Display\n";
    cin>>ch;
    if(ch==1)
    {
        if(top==(sizeof(a)/sizeof(int))-1)
            cout<<"Stack Overflow !!!!! \n";
        else
        {
            top++;
            cin>>a[top];
        }
    }
    else if(ch==2)
    {
        if(top==-1)
        {
            cout<<"Stack Underflow !!!!! \n";
        }
        else
        {
            cout<<"Popping out "<<a[top]<<"\n";
            top--;
        }
    }
    else
    {
        cout<<"The elements are : ";
        for(i=top;i>=0;i--)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Continue ?('y'/'n')";
    cin>>var;
    if(var=='y')
        continue;
    else
        break;
    }
    return 0;
}
