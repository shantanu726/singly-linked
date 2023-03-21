//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

Node *rev(Node *head)
{
    Node *prev=NULL,*cur=head,*next;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
Node * mergeResult(Node *node1,Node *node2)
{
    if(node1==NULL)
        return node2;
    if(node2==NULL)
        return node1;
    Node *t=new Node;
    t->data=-1;
    t->next=NULL;
    Node *c=t;
    while(node1!=NULL && node2!=NULL)
    {
        if(node1->data<node2->data)
        {
            Node *f=new Node;
            f->data=node1->data;
            f->next=NULL;
            c->next=f;
            node1=node1->next;
        }
        else
        {
            Node *f=new Node;
            f->data=(node2->data);
            f->next=NULL;
            c->next=f;
            node2=node2->next;
        }
        c=c->next;
    }
    if(node1!=NULL)
        c->next=node1;
    if(node2!=NULL)
        c->next=node2;
    return rev(t->next);
}