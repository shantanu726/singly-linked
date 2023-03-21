#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    // Function to count nodes of a linked list.
    // int getCount(struct Node *head)
    // {
    //     Node *temp = head;
    //     int c = 0;
    //     if (head == NULL)
    //     {
    //         return 0;
    //     }
    //     while (temp != NULL)
    //     {
    //         c++;
    //         temp = temp->next;
    //     }
    //     return c;
    //     // Code here
    // }

    bool search(struct Node *head, int k){
     Node *temp=head;
     int c=0;
        while(temp!=NULL){
   
        if(temp->data==k){
            return 1;c=1;
            temp=temp->next;
        }
    }

if(c=0){
    return 0;
}
    }

    /*bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}*/
};

int main()
{
    int t,k;
    cin >> t;
    cin>>k;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data; // <<< IT FOR MAKING HEAD  
        struct Node *head = new Node(data); // ^^^ POINTING HEAD

        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        cout <<"No of Nodes : "<< ob.search(head,k) << endl;
    }
    return 0;
}