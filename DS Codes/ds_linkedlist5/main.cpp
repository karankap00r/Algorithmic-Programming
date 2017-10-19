//REVERSE A LINKED LIST USING STACK
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node* next;
};
node* head=NULL;
void insert(int n)
{
    node* temp=new node;
    temp->info=n;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        node* temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        return;
    }
}
void delete1(int n)
{
    if(head==NULL)
    {
        cout<<"List Is Empty \n";
    }
    else
    {
        node* temp1=head;
        while(temp1->next!=NULL)
        {
           if(temp1->next->info==n)
           {
               node* temp=temp1->next;
               temp1->next=temp1->next->next;
               delete temp;
           }
           temp1=temp1->next;
        }
    }
}
void display()
{
    node* temp1=head;
    cout<<"The list is : ";
    while(temp1!=NULL)
    {
        cout<<temp1->info<<" ";
        temp1=temp1->next;
    }
    cout<<"\n";
}
void reverse1()
{
    stack<node*> s;
    node* temp1=head;
    while(temp1->next!=NULL)
    {
        s.push(temp1);
        temp1=temp1->next;
    }
    head=temp1;
    while(!s.empty())
    {
        temp1->next=s.top();
        temp1=temp1->next;
        s.pop();
    }
    temp1->next=NULL;
}
int main()
{
    insert(40);
    insert(56);
    insert(27);
    insert(96);
    display();      //40 56 27 96
    delete1(27);
    display();      //40 56 96
    reverse1();
    display();      //96 56 40
    return 0;
}
