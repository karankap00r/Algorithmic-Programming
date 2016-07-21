#include<iostream>
using namespace std;
int main()
{
    int n,i,cnt,a[100],ind;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ind=0;
    cnt=1;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[ind])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if(cnt==0)
        {
            ind=i;
            cnt=1;
        }
    }
    if(cnt==0)
    {
        cout<<"None found";
        return 0;
    }
    else
    {
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[ind])
            {
                cnt++;
            }
        }
    }
    if(2*cnt>=n)
    {
        cout<<a[ind];
    }
    else
    {
        cout<<"Not Found";
    }
    return 0;
}