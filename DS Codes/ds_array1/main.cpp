#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],ch,n,i,item,flag,j,pos,beg,last,mid;
    n=0;
    while(1)
    {
        flag=0;
    cout<<"Options are : \n";
    cout<<"1.Insert an element \n";
    cout<<"2.Delete an element \n";
    cout<<"3.Search for an element \n";
    cout<<"4.Display \n";
    cin>>ch;
    if(ch==1)
    {
        if(n==0)
        {
            cout<<"\nHow many elements ? : ";
            cin>>n;
            for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
            sort(a,a+n);
        }
        else
        {
            cin>>item;
            for(i=0;i<n;i++)
            {
                if(item<a[i])
                {
                    flag=1;
                    for(j=n;j>i;j--)
                    {
                        a[j]=a[j-1];
                    }
                    a[i]=item;
                    n++;
                }
            }
            if(flag==0)
            {
                a[n]=item;
                n++;
            }
        }
    }
    else if(ch==2)
    {
        if(n==0)
        {
            cout<<"\nNothing to delete.\n";
        }
        else
        {
            cout<<"Enter element to delete : ";
            cin>>item;
            for(i=0;i<n;i++)
            {
                if(a[i]==item)
                {
                    flag=1;
                    for(j=i;j<n-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    n--;
                }
            }
            if(flag==0)
            {
                cout<<"Item does not exist in the array.\n";
            }
        }
    }
    else if(ch==3)
    {
        if(n==0)
        {
            cout<<"\nArray is empty.Insert some data first\n";
        }
        else
        {
            cout<<"\nEnter element to search\n";
            cin>>item;
            last=n-1;
            beg=0;
            while(beg<last)
            {
                mid=(beg+last)/2;
                if(a[mid]==item)
                {
                    flag=1;
                    pos=mid;
                    break;
                }
                else if(item<a[mid])
                {
                    last=mid-1;
                }
                else
                {
                    beg=mid+1;
                }
            }
            if(flag==0)
            {
                cout<<"\nNumber not found\n";
            }
            else
            {
                cout<<"\nNumber found at position "<<pos+1<<"\n";
            }
        }
    }
    else
    {
        if(n==0)
        {
            cout<<"Nothing to display\n";
        }
        else
        {
            cout<<"Elements are : ";
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<"\nPress 'Y' or 'y' to continue and 'N' or 'n' to exit.(without quotes) : ";
    char var;
    cin>>var;
    if(var=='Y'||var=='y')
        continue;
    else
        break;
    }
    return 0;
}
