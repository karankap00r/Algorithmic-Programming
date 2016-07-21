#include <iostream>
using namespace std;
 
struct node
{
    int data;
    struct node *left,*right;
};
 
typedef struct node Node;
 
void printList(Node *head)
{
    cout<<"Extracted Double Linked list is:\n";
    while (head)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
}
 
Node* newNode(int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
 
void push(Node** tail,Node* root)
{
    if(*tail==NULL)
    {
        *tail=root;
        root->left=root->right=NULL;
        return;
    }
    (*tail)->right=root;
    root->left=*tail;
    root->right=NULL;
    *tail=root;
}
 
Node* BToDLL(Node* root,Node** head)
{
    if(root==NULL)
        return NULL;
 
    Node *l=root->left,*r=root->right;
 
    BToDLL(l,head);
 
    static Node* tail=NULL;
 
    if(*head==NULL) *head=root;
 
    push(&tail,root);
 
    BToDLL(r,head);
}
 
int main()
{
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);
 
    Node* head = NULL;
    BToDLL(root, &head);
 
    printList(head);
    return 0;
}