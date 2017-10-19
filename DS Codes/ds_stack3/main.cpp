#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    cout<<"size : "<<s.size()<<"\n";
    s.push(23);
    s.push(45);
    s.push(76);
    cout<<"now,size :"<<s.size()<<"\n";
    cout<<"Elements : ";
    while(s.empty()!=true)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\nNow size : "<<s.size()<<"\n";
    return 0;
}
