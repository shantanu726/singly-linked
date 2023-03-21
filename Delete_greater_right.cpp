//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* temp=NULL;
    Node* fun(Node* root){
        if(!root)   return root;
        temp=root;
        root->next=fun(root->next);
        if(root->data<temp->data){
            delete root;
            return temp;
        }
        else{
            temp=root;
        }
        return root;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        return fun(head);
    }
*/int helper(Node*p,Node*q,Node*&head){
   if(p==NULL){
       return -1;
   }
   int x=helper(p->next,p,head);
   if(p->data<x){
       if(q!=NULL){
       q->next=p->next;
       }else{
           head=p->next;
       }
       delete p;
       return x;
   }else{
       return p->data;
   }
}


class Solution
{
   public:
   Node *compute(Node *head)
   {
       // your code goes here
       Node*p=head;
       Node*q=NULL;
       helper(p,q,head);
    return head;   
   }
   
   
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends