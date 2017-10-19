#include<bits/stdc++.h>
using namespace std;
struct node{
    int info;
    node* next;
};
node* head = NULL;
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
    node* temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
 }
void print()
{
    node* temp=head;
    cout<<"The List is : ";
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void reverse()
{
    node* previous=NULL;
    node* next=NULL;
    node* current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}
int main()
{
    insert(2);
    insert(5);
    insert(8);
    insert(10);
    insert(12);
    print();        //2,5,8,10,12
    reverse();
    print();        //12,10,8,5,2
    return 0;
}

