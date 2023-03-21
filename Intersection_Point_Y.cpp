//{ Driver Code Starts
#include <iostream>

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
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int intersectPoint(Node *head1, Node *head2)
{ /*

int intersectPoint(Node *head1, Node *head2){
 Node *a=headA;
 Node *b=headB;

     while(a!=b)
     {
       a=a==NULL ? headB : a->next;
       b=b==NULL ? headA : b->next;
     }
     return b->data

}
     ------------------------------------

     int intersectPoint(Node* head1, Node* head2)
 {
    // Your Code Here
    if(head1 == NULL || head2 == NULL)
        return 0;

    Node *curr1 = head1;
    Node *curr2 = head2;

    while(curr1 != curr2) {
        if(curr1 == NULL)
            curr1 = head2;
        else
            curr1 = curr1->next;

        if(curr2 == NULL)
            curr2 = head1;
        else
            curr2 = curr2->next;
    }
    return curr1->data;
 }
 */

    // Your Code Here
    Node *temp1 = head1;
    Node *temp2 = head2;
    int count1 = 0, count2 = 0;

    while (temp1 != NULL)
        temp1 = temp1->next, count1++;
    while (temp2 != NULL)
        temp2 = temp2->next, count2++;

    int extralen = abs(count1 - count2);
    temp1 = head1;
    temp2 = head2;

    if (count1 >= count2)
    {
        while (extralen > 0)
        {
            temp1 = temp1->next;
            extralen--;
        }
    }
    else
    {
        while (extralen-- > 0)
            temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL && (temp1 != temp2))
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1->data;
    }

    return -1;
}