
#include <bits/stdc++.h>

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
}  *start = NULL; // struct Node *start = NULL;

/*
class Node{
    public:
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
}*/

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* segregate(Node *head) {
        // Add code here
        Node *temp = head;
        int arr[] = {0, 0, 0};
        while(temp)
        {
            if(temp->data == 0) arr[0]++;
            else if(temp->data == 1) arr[1]++;
            else arr[2]++;
            temp = temp->next;
        }

        temp = head;

        for(int i = 0; i < 3; i++)
        {
            while(arr[i] != 0)
            {
                temp->data = i;
                temp = temp->next;
                arr[i]--;
            }
        }
        return head;
    }

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
     Node* segregate(Node *head) {

   //Approach 1-Data replacement is allowed
           // Add code here
       int zerocount=0;
       int onecount=0;
       int twocount=0;

       Node* temp=head;
       while(temp!= NULL){
           if(temp -> data==0){
               zerocount++;
           }

           else if(temp->data==1){
               onecount++;
           }

           else if(temp->data==2){
               twocount++;
           }

           temp=temp->next;
       }

       temp=head;
       while(temp!=NULL){
           if(zerocount!=0){
               temp->data=0;
               zerocount--;
           }
           else if(onecount!=0){
               temp->data=1;
               onecount--;
           }

           else if(twocount!=0){
               temp->data=2;
               twocount--;
           }

           temp=temp->next;
       }
       return head;

   }
};
*/

class Solution
{
public:
    Node *segregate(Node *head)
    {

        int zero = 0, one = 0, two = 0;

        Node *curr = head;

        while (curr != NULL)
        {

            if (curr->data == 0)
                zero++;
            else if (curr->data == 1)
                one++;
            else
                two++;

            curr = curr->next;
        }

        curr = head;

        while (zero--)
        {
            curr->data = 0;
            curr = curr->next;
        }

        while (one--)
        {
            curr->data = 1;
            curr = curr->next;
        }

        while (two--)
        {
            curr->data = 2;
            curr = curr->next;
        }
        return head;
    }
};

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
           // temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// Driver Code Ends        https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?page=1&difficulty[]=0&company[]=Amazon&company[]=Microsoft&company[]=Flipkart&category[]=Linked%20List&sortBy=submissions
