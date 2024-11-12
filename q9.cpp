#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int val):data(val),next(nullptr){}
};
Node* findMiddle(Node* head){
Node* slow=head;
Node* fast=head;
while(fast&&fast->next){
slow=slow->next;
fast=fast->next->next;
}
return slow;
}
void printList(Node* head){
while(head){
cout<<head->data<<" ";
head=head->next;
}
cout<<endl;
}
int main(){
Node* head=new Node(1);
head->next=new Node(2);
head->next->next=new Node(3);
head->next->next->next=new Node(4);
head->next->next->next->next=new Node(5);
Node* middle=findMiddle(head);
cout<<middle->data<<endl;
}
