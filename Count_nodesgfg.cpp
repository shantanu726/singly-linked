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
    int getCount(struct Node *head)
    {
        Node *temp = head;
        int c = 0;
        if (head == NULL)
        {
            return 0;
        }
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
        // Code here
    }
};

int main()
{
    int t;
    cin >> t;
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
        cout <<"No of Nodes : "<< ob.getCount(head) << endl;
    }
    return 0;
}