

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}



/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    Node *rev(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *temp = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }

    Node *addOne(Node *head)
    {
        Node *revhead = rev(head);
        Node *temp = revhead, *prev = NULL;
        ;
        int carry = 0;
        while (temp)
        {
            if (temp->data < 9)
            {
                temp->data = temp->data + 1;
                carry = 0;
                break;
            }
            else
            {
                carry = 1;
                temp->data = 0;
            }
            prev = temp;
            temp = temp->next;
        }
        if (carry)
        {
            Node *ex = new Node(carry);
            prev->next = ex;
        }
        return rev(revhead);
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends