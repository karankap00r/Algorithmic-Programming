#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node *next;
};
node* f=NULL;
node* r=NULL;
node* ptr=NULL;
node* newptr=NULL;
int main()
{
    int ch;
    char var;
    cout<<"WELCOME TO QUEUES \n\n";
    while(1){
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Display\n";
    cin>>ch;
    if(ch==1)
    {
        newptr=NULL;
        newptr=new node;
        if(f==NULL)
        {
            cout<<"Enter info for the node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            f=newptr;
            r=newptr;
        }
        else
        {
            cout<<"Enter info for the node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            r->next=newptr;
            r=newptr;
        }
    }
    else if(ch==2)
    {
        if(f==NULL)
        {
            cout<<"Queue is empty !!!! \n";
        }
        else if(f==r)
        {
            node* temp=f;
            f=r=NULL;
            delete temp;
        }
        else
        {
            node* temp=f;
            f=f->next;
            delete temp;
        }
    }
    else
    {
        cout<<"The elements are : ";
        for(ptr=f;ptr!=NULL;ptr=ptr->next)
        {
            cout<<ptr->info<<" ";
        }
        cout<<"\n";
    }
    cout<<"Continue ? ('y' or 'n')";
    cin>>var;
    if(var=='y'||var=='Y')
        continue;
    else
        break;
    }
    return 0;
}
