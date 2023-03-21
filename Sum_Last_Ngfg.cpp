
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
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
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

int sumOfLastN_Nodes(struct Node* head, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n,m,tmp;
        cin>>m>>n;
        while(m--){
            cin>>tmp;
            append(&head, tmp);
        }
        cout<<sumOfLastN_Nodes(head, n)<<endl;
    }
	return 0;
}
struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};


int sumOfLastN_Nodes(struct Node* head, int n)
{
      // Code here
      Node * ptr=head;
      int count=0;
      while(ptr!=NULL){
          count++;
          ptr = ptr->next;
      }
      
      int len = count-n;
      ptr = head;
      while(len--){
          ptr = ptr->next;
      }
      
      int sum=0;
      while(ptr!=NULL){
          sum+=ptr->data;
          ptr = ptr->next;
      }
      return sum;
}




int sumOfLastN_Nodes(struct Node* head, int n)
{
       // Code here
     struct Node*temp=head;
    int ans=0;
     int total=0;
     while(head)
     {
        total++;
      
        head=head->next;
     }
     head=temp;
     int i=0;
     n= total-1-n;
     while(head)
     {
         if(i>n)
         ans+=head->data;
         head=head->next;
         i++;
     }
     
     return ans;
}



Node * curr = head;
     int cnt = 0;
     while(curr != NULL){
         cnt++;
         curr = curr->next;
     }
     curr = head;
     int sum = 0;
     for(int i=0; i<cnt; i++){
         if(i >= (cnt-n) && curr!=NULL){
             sum += curr->data;
         }
         curr = curr->next;
     }
     return sum;

// function should return sum of last n nodesint 

int sumOfLastN_Nodes(struct Node* head, int n)
{
    int sum = 0;
    int i=0;
    Node* curr = head;
    while(i<n && curr){
        i++;
        curr = curr->next;
    }
    Node* x = head;
    while(curr){
        x = x->next;
        curr = curr->next;
    }
    while(x){
        sum += (x->data);
        x = x->next;
    }
    return sum;
}

/*1
6 3
5 9 6 3 4 10
17
*/