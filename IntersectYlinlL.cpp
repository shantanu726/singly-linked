//https://practice.geeksforgeeks.org/problems/eae1fbd0ac8f213a833d231e26ba4d829e79dd9c/1

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

Node* inputList(int size)
{
    if (size == 0) return NULL;

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

class Solution
{
public:

int len(Node* ndlen){
    int l=0;
    while(ndlen){
        l++;
        ndlen=ndlen->next;
    }
    return l;
}
    int intersectPoint(Node* head1, Node* head2)
    {
       Node *tem1=head1,*tem2=head2;
       
       int hdl1=len(tem1);
       int hdl2=len(tem2);
       
       int k=abs(hdl1-hdl2);
       
       while(k--){
           if(hdl1>hdl2){
               head1=head1->next;
           }else{
               head2=head2->next;
           }
       }
       
       
       while(head1!=head2){
           head1=head1->next;
           head2=head2->next;
       }
       
       return head1->data;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends