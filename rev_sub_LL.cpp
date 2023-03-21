/*
Reverse a sublist of a linked list


Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:

Input :
N = 10
Linked List = 1->7->5->3->9->8->10
                      ->2->2->5->NULL
m = 1, n = 8
Output : 2 10 8 9 3 5 7 1 2 5 
Explanation :
The nodes from position 1 to 8 
are reversed, resulting in 
2 10 8 9 3 5 7 1 2 5.
*/

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(m==1)
        {
            Node *end=NULL,*q=head;
            int i=0;
            while(q!=NULL && i<n)
            {
                i++;
                end=q;
                q=q->next;
            }
            end->next=NULL;
            Node *curr=head,*prev=NULL,*nex=NULL;
            while(curr!=NULL)
            {
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
            }
            head->next=q;
            return prev;
        } 
        else
        {
            Node *strt=head,*p=NULL,*end=NULL,*q=head;
            int j=0;
            while(j<n && q!=NULL )
            {
                j++;
                end=q;
                q=q->next;
            }
            end->next=NULL;
            int i=1;
            while(strt!=NULL && i<m)
            {
                i++;
                p=strt;
                strt=strt->next;  
            }
            p->next=NULL;
            Node *curr=strt,*prev=NULL,*nex=NULL;
            while(curr!=NULL)
            {
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
            }
            strt->next=q;
            p->next=prev;
            return head;
        }
    }
};

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
