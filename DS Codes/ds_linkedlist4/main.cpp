// DOUBLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* previous;
    node* next;
};
node* head=NULL;
int main()
{
    int ch,x;
    while(1){
    cout<<"Select your choice :\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Display\n";
    cin>>ch;
    if(ch==1)
    {
        node* temp=new node;
        cin>>temp->data;
        temp->next=NULL;
        temp->previous=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            node* temp1=head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->previous=temp1;
        }
    }
    else if(ch==2)
    {
        if(head==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {
            cout<<"Enter the element to be deleted : ";
            cin>>x;
            for(node* temp=head;temp->next!=NULL;temp=temp->next)
            {
                if(temp->data==x)
                {
                    node* temp1=temp;
                    temp->next->previous=temp->previous;
                    temp->previous->next=temp->next;
                    delete temp1;
                }
            }
        }
    }
    else
    {
        if(head==NULL)
        {
            cout<<"List is empty\n";
        }
        else
        {
            cout<<"The List is : ";
            for(node* temp1=head;temp1!=NULL;temp1=temp1->next)
            {
                cout<<temp1->data<<" ";
            }
            cout<<"\n";
        }
    }
    char choice;
    cout<<"Continue ? ('y'/'n')\n";
    cin>>choice;
    if(choice=='y')
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
