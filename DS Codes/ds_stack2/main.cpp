#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node* next;
};
node *newptr=NULL;
node *top=NULL;
int main()
{
    int ch;
    char var;
    while(1){
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Display\n";
    cin>>ch;
    if(ch==1)
    {
        newptr=NULL;
        newptr=new node;
        if(top==NULL)
        {
            cout<<"Enter info for node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            top=newptr;
        }
        else
        {
            cout<<"Enter info for node : ";
            cin>>newptr->info;
            newptr->next=NULL;
            newptr->next=top;
            top=newptr;
        }
    }
    else if(ch==2)
    {
        if(top==NULL)
        {
            cout<<"Nothing to delete !!!! \n";
        }
        else
        {
            node* temp=top;
            top=top->next;
            delete temp;
        }
    }
    else
    {
        cout<<"The elements are : ";
        for(node* ptr=top;ptr!=NULL;ptr=ptr->next)
        {
            cout<<ptr->info<<" ";
        }
        cout<<"\n";
    }
    cout<<"Continue ? ('y'/'n')";
    cin>>var;
    if(var=='y'||var=='Y')
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
