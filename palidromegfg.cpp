//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *reverse(Node *head)
    {
        Node *prev = NULL,*cur = head,*next = NULL;
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *temp = head;
        int cnt = 0;
        
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        if(cnt == 1 or cnt == 0)
            return true;
        temp = head;
        cnt = cnt / 2;
        
        
        /*  Node* middle(Node* head)

    {

        Node* slow=head;

        Node* fast=head;

        while(fast and fast->next)

        {

            slow=slow->next;

            fast=fast->next->next;

        }

        if(fast)slow=slow->next;

        return slow;

    }*/
        while(cnt > 1)
        {
            temp = temp->next;
            cnt--;
        }
        Node *head2 = temp->next;
        temp->next = NULL;
        head2 = reverse(head2);
        while(head != NULL)
        {
            if(head->data != head2->data)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};


//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
