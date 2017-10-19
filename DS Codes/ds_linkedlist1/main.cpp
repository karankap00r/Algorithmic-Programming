#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node* next;
};
node* start=NULL;
node* ptr=NULL;
int main()
{
    int flag,ch,item,pos;
    char var;
    cout<<"WELCOME TO LINKED LISTS\n\n";
    while(1){
            flag=0;
    cout<<"1.Insert element/elements\n";
    cout<<"2.Delete an element\n";
    cout<<"3.Search an element\n";
    cout<<"4.Display\n\n";
    cin>>ch;
    if(ch==1)
    {
        node* newptr=NULL;
        newptr=new node;
        if(start==NULL)
        {
            cout<<"Enter information for node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            start=newptr;
            ptr=newptr;
        }
        else
        {
            cout<<"Enter information for node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            ptr->next=newptr;
            ptr=newptr;
        }
    }
    else if(ch==2)
    {
        if(start==NULL)
        {
            cout<<"Linked List is empty\n";
        }
        else
        {
            cin>>item;
            if(start->info==item)
            {
                node* temp=start;
                start=start->next;
                delete temp;
            }
            else{
            for(ptr=start;ptr->next!=NULL;ptr=ptr->next)
            {
                if(ptr->next->info==item)
                {
                    node* temp=ptr->next;
                    ptr->next=ptr->next->next;
                    delete temp;
                }
            }
            }
        }
    }
    else if(ch==3)
    {
        if(start==NULL)
        {
            cout<<"The linked list is empty\n";
        }
        else
        {
            int i=0;
            cout<<"Enter element to search : ";
            cin>>item;
            for(ptr=start;ptr!=NULL;ptr=ptr->next)
            {
                i++;
                if(ptr->info==item)
                {
                    flag=1;
                    pos=i;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"Number not found\n";
            }
            else
            {
                cout<<"Number found at position "<<pos<<"\n";
            }
        }
    }
    else
    {
        if(start==NULL)
        {
            cout<<"Linked List is empty\n";
        }
        else
        {
            cout<<"The nodes are : ";
            for(ptr=start;ptr!=NULL;ptr=ptr->next)
            {
                cout<<ptr->info<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<"Press 'Y' or 'y' to continue,'N' or 'n' to exit: ";
    cin>>var;
    if(var=='Y'||var=='y')
        continue;
    else
        break;
    }
    return 0;
}
