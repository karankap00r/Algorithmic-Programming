//C++ style using vector
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,cap,j;
    vector<int> v;
    cin>>n;
    v.push_back(2);
    for(i=3;i<=n;i+=2)
    {
        cap=sqrt(i)+1;
        bool isprime=true;
        for(j=0;j<v.size();j++)
        {
            if(v[j]>cap)
            {
                break;
            }
            if(i%v[j]==0)
            {
                isprime=false;
            }
        }
        if(isprime==true)
        {
            v.push_back(i);
        }
    }
    for(i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
