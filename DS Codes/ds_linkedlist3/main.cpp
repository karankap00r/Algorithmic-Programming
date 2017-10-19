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
void reverse(node* p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    p->next->next=p;
    p->next=NULL;
}
int main()
{
    insert(2);
    insert(5);
    insert(8);
    insert(10);
    insert(12);
    print();        //2,5,8,10,12
    reverse(head);
    print();        //12,10,8,5,2
    return 0;
}

