/*
Given a linked list where every node represents a linked list and contains two pointers of its type:

Pointer to next node in the main list (we call it ‘right’ pointer in the code below)
Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below).
Note: All linked lists are sorted and the resultant linked list should also be sorted

Examples:

Input:    5 -> 10 -> 19 -> 28
               |        |         |        |
              V       V       V       V
              7      20      22     35
               |                 |        |
              V               V       V
              8               50     40
              |                          |
             V                        V
            30                       45


Output: 5->7->8->10->19->20->22->28->30->35->40->45->50

Input:    3 -> 10 -> 7 -> 14
               |        |         |        |
              V       V       V       V
              9      47      15     22
               |                 |
              V                V
              17              30

Output: 3->9->7->10->14->15->17->22->30->47

Follow the given steps to solve the problem:

Recursively call to merge the current linked list with the next linked list
If the current linked list is empty or there is no next linked list then return the current linked list (Base Case)
Start merging the linked lists, starting from the last linked list
After merging the current linked list with the next linked list, return the head node of the current linked list






class Node {
public:
    int data;
    Node *right, *down;
};

Node* head = NULL;

// An utility function to merge two sorted
// linked lists
Node* merge(Node* a, Node* b)
{

    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;

    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;

    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node* result;

    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }

    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* root)
{

    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;

    // Recur for list on right
    root->right = flatten(root->right);

    // Now merge
    root = merge(root, root->right);

    // Return the root
    // it will be in turn merged with its left
    return root;
}
.........................................................................................................................................
Flattening a Linked List using Priority Queues:
The idea is, to build a Min-Heap and push head node of every linked list into it and then use Extract-min function to get minimum element from priority queue and then move forward in that linked list.

Follow the given steps to solve the problem:

Create a priority queue(Min-Heap) and push the head node of every linked list into it
While the priority queue is not empty, extract the minimum value node from it and if there is a next node linked to the minimum value node then push it into the priority queue
Also, print the value of the node every time after extracting the minimum value node








// Linked list Node
struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// comparator function for priority queue
struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

void flatten(Node* root)
{
    priority_queue<Node*, vector<Node*>, mycomp> p;
    // pushing main link nodes into priority_queue.
    while (root != NULL) {
        p.push(root);
        root = root->next;
    }

    // Extracting the minimum node
    // while priority queue is not empty
    while (!p.empty()) {

        // extracting min
        auto k = p.top();
        p.pop();

        // printing  least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
}

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution
{

public:
    Node *merge(Node *list1, Node *list2)
    {

        // base cases

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        Node *result;

        if (list1->data < list2->data)
        {

            result = list1;

            result->bottom = merge(list1->bottom, list2);
        }
        else
        {

            result = list2;

            result->bottom = merge(list1, list2->bottom);
        }

        return result;
    }

    Node *flatten(Node *root)

    {

        // Your code here

        if (root == nullptr || root->next == nullptr)
            return root;

        return merge(root, flatten(root->next));
    }
};

//{ Driver Code Starts.

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends