//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->data<=list2->data){
        list1->next=sortedMerge(list1->next,list2);
        return list1;
    }
    else{
        list2->next=sortedMerge(list1,list2->next);
    }
    return list2;
    
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{   if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node*fh=NULL;
    Node*ft=NULL;
    if(head1->data<=head2->data)
    {
        fh=head1;
        ft=head1;
        head1=head1->next;
    }
    else
    {
        fh=head2;
        ft=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            ft->next=head1;
            ft=head1;
            head1=head1->next;
        }
        else
        {
            ft->next=head2;
            ft=head2;
            head2=head2->next;
        }
    }
    if(head1==NULL)
    {
        while(head2!=NULL)
        {
            ft->next=head2;
            ft=head2;
            head2=head2->next;
        }
    }
    if(head2==NULL)
    {
        while(head1!=NULL)
        {
            ft->next=head1;
            ft=head1;
            head1=head1->next;
        }
    }
    return fh;
}  