#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *right,*down;
};

typedef struct node Node;

void push(Node** head,int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->down=*head;
    if(!(*head)) newnode->right=NULL;
    else newnode->right=(*head)->right;
    *head=newnode;
}

void printList(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->down;
    }
}

Node* SortedMerge(Node* a,Node *b)
{
    if(!a && !b) return NULL;
    if(!a && b) return b;
    if(a && !b) return a;

    Node* res=NULL;

    if(a->data<=b->data)
    {
        res=a;
        res->down=SortedMerge(a->down,b);
    }
    else
    {
        res=b;
        res->down=SortedMerge(a,b->down);
    }
    return res;
}

Node* flatten(Node* root)
{
    if(!root) return NULL;
    root->right=flatten(root->right);
    root->down=flatten(root->down);
    root=SortedMerge(root->right,root);
    root->right=NULL;
    return root;
}

int main()
{
    //FREI("input.txt");
    //FREO("output.txt");
    //IOS;
    //citi;
    Node* root = NULL;

    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);

    // Let us print the flatened linked list
    printList(root);
    return 0;
}
