#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;
Node(int val):data(val),next(nullptr),prev(nullptr){}
};
class DoublyCircularLinkedList{
Node* head;
public:
DoublyCircularLinkedList():head(nullptr){}
void insertAtBeginning(int val){
Node* newNode=new Node(val);
if(!head){
newNode->next=newNode;
newNode->prev=newNode;
head=newNode;
}else{
newNode->next=head;
newNode->prev=head->prev;
head->prev->next=newNode;
head->prev=newNode;
head=newNode;
}
}
void insertAtEnd(int val){
Node* newNode=new Node(val);
if(!head){
newNode->next=newNode;
newNode->prev=newNode;
head=newNode;
}else{
newNode->next=head;
newNode->prev=head->prev;
head->prev->next=newNode;
head->prev=newNode;
}
}
void insertAtPosition(int val,int position){
Node* newNode=new Node(val);
if(position==1){
insertAtBeginning(val);
return;
}
Node* temp=head;
int count=1;
while(temp->next!=head&&count<position-1){
temp=temp->next;
count++;
}
if(temp->next==head&&count<position-1){
insertAtEnd(val);
}else{
newNode->next=temp->next;
newNode->prev=temp;
temp->next->prev=newNode;
temp->next=newNode;
}
}
void deleteFromBeginning(){
if(!head)return;
if(head->next==head){
delete head;
head=nullptr;
}else{
head->prev->next=head->next;
head->next->prev=head->prev;
Node* temp=head;
head=head->next;
delete temp;
}
}
void deleteFromEnd(){
if(!head)return;
if(head->next==head){
delete head;
head=nullptr;
}else{
head->prev->prev->next=head;
Node* temp=head->prev;
head->prev=head->prev->prev;
delete temp;
}
}
void deleteAtPosition(int position){
if(position==1){
deleteFromBeginning();
return;
}
Node* temp=head;
int count=1;
while(temp->next!=head&&count<position){
temp=temp->next;
count++;
}
if(temp->next==head&&count<position){
deleteFromEnd();
}else{
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
delete temp;
}
}
void traverseForward(){
if(!head)return;
Node* temp=head;
do{
cout<<temp->data<<" ";
temp=temp->next;
}while(temp!=head);
cout<<endl;
}
void traverseBackward(){
if(!head)return;
Node* temp=head->prev;
do{
cout<<temp->data<<" ";
temp=temp->prev;
}while(temp!=head->prev);
cout<<endl;
}
bool search(int val){
if(!head)return false;
Node* temp=head;
do{
if(temp->data==val)return true;
temp=temp->next;
}while(temp!=head);
return false;
}
};
int main(){
DoublyCircularLinkedList list;
list.insertAtBeginning(1);
list.insertAtEnd(2);
list.insertAtEnd(3);
list.insertAtEnd(4);
list.insertAtPosition(5,3);
list.traverseForward();
list.deleteFromBeginning();
list.deleteFromEnd();
list.deleteAtPosition(2);
list.traverseForward();
cout<<list.search(3)<<endl;
cout<<list.search(5)<<endl;
list.traverseBackward();
}

