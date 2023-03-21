// C++ implementation of the approach
#include <iostream>
using namespace std;

// Represents node of the linked list
struct Node {
	int data;
	Node* next;
};

// Function to insert a node at the
// end of the linked list
void insert(Node** root, int item)
{
	Node *ptr = *root, *temp = new Node;
	temp->data = item;
	temp->next = NULL;

	if (*root == NULL)
		*root = temp;
	else {
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

// Function to print the sum of even
// and odd nodes of the linked 
/*
void evenOdd(Node* root)
{
	int odd = 0, even = 0;
	Node* ptr = root;
	while (ptr != NULL) {

		// If current node's data is even
		if (ptr->data % 2 == 0)
			even += ptr->data;

		// If current node's data is odd
		else
			odd += ptr->data;

		// ptr now points to the next node
		ptr = ptr->next;
	}

	cout << "Even Sum = " << even << endl;
	cout << "Odd Sum = " << odd << endl;
}*/


void evenOdd(Node* root){
    int odd=0,even=0;
    Node *ptr = root;
    while(ptr!=NULL){
    if(ptr->data%2==0){
        even=even+ptr->data;
        ptr=ptr->next;
    }else{
        odd=odd+ptr->data;
        ptr=ptr->next;
    }
    
}
cout<<even<<endl;
    cout<<odd<<endl;
}
int main()
{
	Node* root = NULL;
	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 7);

	evenOdd(root);

	return 0;
}
