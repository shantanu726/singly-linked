// /*Intersection Point in Y Shaped Linked Lists

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

// Example 1:

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL


// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// */


// //{ Driver Code Starts
// //Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// /* Link list Node */
// struct Node
// {
//     int data;
//     struct Node *next;
//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// Node* inputList(int size)
// {
//     if (size == 0) return NULL;

//     int val;
//     cin >> val;

//     Node *head = new Node(val);
//     Node *tail = head;

//     for (int i = 0; i < size - 1; i++)
//     {
//         cin >> val;
//         tail->next = new Node(val);
//         tail = tail->next;
//     }

//     return head;
// }


// // } Driver Code Ends
// /* Linked List Node
// struct Node {
//   int data;
//   struct Node *next;
//   Node(int x) {
//     data = x;
//     next = NULL;
//   }
// }; */

// class Solution
// {
// public:

// int len(Node* ndlen){
//     int l=0;
//     while(ndlen){
//         l++;
//         ndlen=ndlen->next;
//     }
//     return l;
// }
//     int intersectPoint(Node* head1, Node* head2)
//     {
//        Node *tem1=head1,*tem2=head2;
       
//        int hdl1=len(tem1);
//        int hdl2=len(tem2);
       
//        int k=abs(hdl1-hdl2);
       
//        while(k--){
//            if(hdl1>hdl2){
//                head1=head1->next;
//            }else{
//                head2=head2->next;
//            }
//        }
       
       
//        while(head1!=head2){
//            head1=head1->next;
//            head2=head2->next;
//        }
       
//        return head1->data;
//     }
// };



// //{ Driver Code Starts.


// /* Driver program to test above function*/
// int main()
// {
//     int T, n1, n2, n3;

//     cin >> T;
//     while (T--)
//     {
//         cin >> n1 >> n2 >> n3;

//         Node* head1 = inputList(n1);
//         Node* head2 = inputList(n2);
//         Node* common = inputList(n3);

//         Node* temp = head1;
//         while (temp != NULL && temp->next != NULL)
//             temp = temp->next;
//         if (temp != NULL) temp->next = common;

//         temp = head2;
//         while (temp != NULL && temp->next != NULL)
//             temp = temp->next;
//         if (temp != NULL) temp->next = common;
        
//         Solution ob;
//         cout << ob.intersectPoint(head1, head2) << endl;
//     }
//     return 0;
// }


// // } Driver Code Ends

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double result = 1.0/6.0;
    double k=1,gh;
    float l=k-0.1;
    float p=1.0;
    int j=1;
   std::cout << std::fixed << std::setprecision(6) << result << std::endl;
    cout<<p;
   gh= std::fixed << std::setprecision(1) << k << std::endl;
    cout<<gh;
    
    return 0;
}