#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(37);
    q.push(45);
    q.push(87);
    cout<<"Size : "<<q.size()<<"\n";
    cout<<q.front()<<"\n";
    cout<<q.back()<<"\n";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\nSize : "<<q.size();
    return 0;
}
