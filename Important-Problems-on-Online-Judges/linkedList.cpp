#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll data;
    node *next;
};
node* newnode(ll data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
}
void print(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void push(node **head,ll data)
{
    node* temp=newnode(data);
    temp->next=(*head);
    (*head)=temp;
}
void addAfter(node *prev,ll data)
{
    node *temp=newnode(data);
    node* x=prev->next;
    prev->next=temp;
    temp->next=x;
}
void append(node **head,ll data)
{
    node *temp=newnode(data);
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    node *cur=*head;
    while(cur->next)
    {
        cur=cur->next;
    }
    cur->next=temp;
}
void delKey(node **head,ll key)
{
    if((*head)->data==key)
    {
        node* temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    node* cur=*head;
    while(cur->next&&cur->next->data!=key)
    {
        cur=cur->next;
    }
    if(cur->next==NULL)
    {
        cout<<"Sorry,not found\n";
    }
    else
    {
        node* temp=cur->next;
        cur->next=temp->next;
        free(temp);
    }
}
ll length(node* head)
{
    ll cnt=0;
    while(head)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}
void swapNodes(node **head,int k1,int k2)
{
    if(*head==NULL)
    {
        return;
    }
    node *p1,*p2,*c1,*c2,*n1,*n2;
    node *cur,*prev;
    p1=NULL;
    p2=NULL;
    c1=NULL;
    c2=NULL;
    cur=*head;
    prev=NULL;
    while(cur!=NULL)
    {
        if(cur->data==k1||cur->data==k2)
        {
            if(c1==NULL)
            {
                p1=prev;
                c1=cur;
            }
            else
            {
                c2=cur;
                p2=prev;
            }
        }
        prev=cur;
        cur=cur->next;
    }
    if(c1==NULL||c2==NULL)
        return;

    if(p1==NULL)
    {
        *head=c2;
    }
    else
    {
        p1->next=c2;
    }
    if(p2==NULL)
    {
        *head=c1;
    }
    else
    {
        p2->next=c1;
    }
    node* temp=c2->next;
    c2->next=c1->next;
    c1->next=temp;
}
node* getNth(node *head,int pos)
{
    pos--;
    while(pos--)
    {
        head=head->next;
    }
    return head;
}
node* getMiddle(node *head)
{
    node* slow=head;
    node* fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* getNthFromEnd(node* head,int pos)
{
    int i=0;
    node* f=head;
    node* s=head;
    while(i<pos)
    {
        f=f->next;
        i++;
    }
    while(f!=NULL)
    {
        f=f->next;
        s=s->next;
    }
    return s;
}
node* reverse(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    node *newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
bool detectLoop(node* head)
{
    if(head==NULL)
        return false;
    node* slow=head;
    node* fast=head;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
node* merge(node* a,node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<=b->data)
    {
        a->next=merge(a->next,b);
        return a;
    }
    else
    {
        b->next=merge(a,b->next);
        return b;
    }
}
node* mergeIterative(node* a,node* b)
{
    node dummy;
    dummy.next=NULL;
    node* tail=&dummy;
    while(1)
    {
        if(a==NULL)
        {
            tail->next=b;
            break;
        }
        else if(b==NULL)
        {
            tail->next=a;
            break;
        }
        else
        {
            if(a->data<=b->data)
            {
                tail->next=a;
                a=a->next;
                tail=tail->next;
            }
            else
            {
                tail->next=b;
                b=b->next;
                tail=tail->next;
            }
        }
    }
    return dummy.next;
}
void printRev(node* head)
{
    if(head==NULL)
        return;
    printRev(head->next);
    cout<<head->data<<" ";
}
bool checkPalin(node* head)
{
    node* temp=getMiddle(head);
    ll len=length(head);
    if(len%2==0)
    {
        node* temp=getNth(head,len/2);
        temp->next=reverse(temp->next);
        node* cur=head;
        node* mid=temp->next;
        while(mid!=NULL)
        {
            if(mid->data!=cur->data)
            {
                return false;
            }
            mid=mid->next;
            cur=cur->next;
        }
    }
    else
    {
        node* temp=getNth(head,(len/2)+1);
        temp->next=reverse(temp->next);
        node* cur=head;
        node* mid=temp->next;
        while(mid!=NULL)
        {
            if(mid->data!=cur->data)
            {
                return false;
            }
            mid=mid->next;
            cur=cur->next;
        }
    }
    return true;
}
void pairWiseSwap(node** head)
{
    if(*head==NULL||(*head)->next==NULL)
        return;
        
    node* cur=*head;
    node* prev=NULL;
    node* next=(*head)->next;
    
    cur->next=next->next;
    next->next=cur;
    (*head)=next;
    
    if(cur->next==NULL)
        return;
    
    prev=cur;
    cur=cur->next;
    next=cur->next;
    while(cur!=NULL&&next!=NULL)
    {
        cur->next=next->next;
        next->next=cur;
        prev->next=next;
        
        prev=cur;
        cur=prev->next;
        next=cur->next;
    }
}
void frontBackSplit(node *head,node **a,node **b)
{
    if(head==NULL||head->next==NULL)
    {
        *a=head;
        *b=NULL;
        return;
    }
    node *slow=head;
    node *fast=head;
    node *prev=NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        prev=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    *a=head;
    if(prev)
    {
        *b=prev->next;
        prev->next=NULL;
    }
    else
    {
        *b=NULL;
    }
}
void mergeSort(node **head)
{
    if(*head==NULL||(*head)->next==NULL)
    {
        return;
    }
    node *a=NULL;
    node *b=NULL;
    frontBackSplit(*head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *head=merge(a,b);
}
node* revGrp(node* head,int k)
{
    node* prev=NULL;
    node* cur=head;
    node* next=NULL;
    int i=0;
    while(i<k&&cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        i++;
    }
    if(head)
        head->next=revGrp(cur,k);
    return prev;
}
void sortedInsert(node** head,node* newnode)
{
    if((*head)==NULL||(*head)->data>=newnode->data)
    {
        newnode->next=(*head);
        (*head)=newnode;
        return;
    }
    else
    {
        node* cur=*head;
        while(cur->next!=NULL&&cur->next->data<newnode->data)
        {
            cur=cur->next;
        }
        newnode->next=cur->next;
        cur->next=newnode;
    }
}
void insSort(node** head)
{
    if(*head==NULL||(*head)->next==NULL)
        return;
    node* sorted=NULL;
    node* cur=(*head);
    while(cur!=NULL)
    {
        node* next=cur->next;
        sortedInsert(&sorted,cur);
        cur=next;
    }
    (*head)=sorted;
}
int main()
{
    node* head=newnode(2);
    push(&head,3);
    addAfter(head->next,7);
    append(&head,5);
    append(&head,8);
    print(head);
    cout<<"\n";
    delKey(&head,9);
    print(head);
    cout<<"\n";
    cout<<length(head)<<"\n";
    swapNodes(&head,5,8);
    print(head);
    cout<<"\n";
    cout<<getNth(head,4)->data;
    cout<<"\n";
    cout<<getMiddle(head)->data<<"\n";
    cout<<getNthFromEnd(head,1)->data<<"\n";
    head=reverse(head);
    print(head);
    cout<<"\n";
    cout<<detectLoop(head)<<"\n";
    //head->next->next->next=head;
    //cout<<detectLoop(head)<<"\n";
    node* a=newnode(1);
    node* b=newnode(2);
    append(&a,3);
    append(&a,5);
    append(&a,7);
    append(&a,9);
    append(&a,11);
    append(&a,13);
    append(&b,4);
    append(&b,6);
    append(&b,8);
    append(&b,10);
    node* res=mergeIterative(a,b);
    cout<<"\n";
    print(res);
    cout<<"\n";
    printRev(res);
    node* c=newnode(1);
    append(&c,2);
    append(&c,3);
    append(&c,4);
    append(&c,3);
    append(&c,2);
    append(&c,1);
    cout<<"\n";
    print(c);
    cout<<"\n";
//    cout<<"\n"<<checkPalin(c);
//    cout<<"\n";
    pairWiseSwap(&c);
    print(c);
    cout<<"\n";
    mergeSort(&c);
    print(c);
    cout<<"\n";
    c=revGrp(c,3);
    print(c);
    cout<<"\n";
    insSort(&c);
    print(c);
    return 0;
}