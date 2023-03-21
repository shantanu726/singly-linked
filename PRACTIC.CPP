#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class solution {
    public:
    struct Node *mid_rev(struct Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
      struct  Node *slow=head, *first=head;
      while(first !=NULL && first->next !=NULL){
            slow=slow->next;
            first=first->next->next;
      }
      return slow->data;
    }
};


int main()
{
   int T,n,ip,f_Data;
struct Node *head = NULL, *tail = NULL;
cin>>n; // HOW MANY ELEMENT YOU WILL BE INSERT :
cin>>f_data;
head = new Node(f_Data);
tail=head;
for(int i=1; i<n; i++){
    cin>>l;
    tail->next = new Node(ip);
    tail=tail->next;
}
solution ob;
head = ob.mid_rev(head);

print(head);
   
}