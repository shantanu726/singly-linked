//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

int modularNode(Node* head, int k);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n, tmp, k;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        cin>>k;
        cout<<modularNode(head, k)<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*Struture of the node of the linked list is as:

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// Your task is to complete the function
// function should return the modular Node
// if no such node is present then return -1


int modularNode(Node* head, int k)
{
	// Code here
int Max=-1;
int i=1;
while(head!=NULL){
    if(i%k==0){
        Max=head->data;
    }
    head=head->next;
    i++;
    
}
return Max;
}




/*

int modularNode(Node* head, int k){
    Node *temp=head,*f,*n;
    int i=0,s=1;
    
    while(temp!=NULL){
        f=(temp->data)%k;
        if(f==0){
            n=(temp->data)/k;
            s=max(s,n);
            
        }
        temp=temp->next;
    }
    return s;
}

*/





