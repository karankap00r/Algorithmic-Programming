#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q[1000],f,r,ch,i;
    char var;
    f=r=-1;
    while(1)
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cin>>ch;
        if(ch==1)
        {
            if(f==-1)
            {
                f=r=0;
                cin>>q[r];
            }
            else if(r==(sizeof(q)/sizeof(int))-1)
            {
                cout<<"No more space !!!!! \n";
            }
            else
            {
                r++;
                cin>>q[r];
            }
        }
        else if(ch==2)
        {
            if(f==-1)
            {
                cout<<"Queue is empty !!!!! \n";
            }
            else if(f==r)
            {
                f=r=-1;
            }
            else
            {
                cout<<"Removing element "<<q[f]<<"\n";
                f++;
            }
        }
        else
        {
            cout<<"The elements are : ";
            for(i=f;i<=r;i++)
            {
                cout<<q[i]<<" ";
            }
            cout<<"\n";
        }
        cout<<"Continue ? ('y' or 'n') : ";
        cin>>var;
        if(var=='y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}
