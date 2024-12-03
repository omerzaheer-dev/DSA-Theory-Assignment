
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=nullptr;
    }
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class LinkedList{
public:
    Node *head;
    LinkedList(){
        head=nullptr;
    }
    void insertAtHead(int val){
        Node *newNode = new Node(val);
        newNode->next=head;
        head=newNode;
    }
    void reverseLinkedList(){
        Node *current=head;
        Node *next;
        Node *previous=nullptr;
        while(current!=nullptr){
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        head=previous;
    }
    void insertAtTail(int val){
        Node *newNode = new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node *temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void deleteAtHead(){
        if(!head){
            cout<<"nothing to del";
        }
        Node * temp = head;
        head=head->next;
        delete temp;
    }
    void deleteAtTail(){
        if(head==nullptr){
            cout<<"nothing to del";
        }
        if(head->next==nullptr){
            delete head;
            head=nullptr;
            return;
        }
        Node * temp = head;
        while(temp->next!=nullptr && temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }
    void deleteAtAnyIndex(int val){
        Node *temp=head;
        if(!head){
            cout<<"nort";
        }
        if(head->data==val){
            deleteAtHead();
            return;
        }
        if(temp->next->data!=val && temp->next!=nullptr){
            temp=temp->next;
        }
        Node *valtodel = temp->next;
        temp->next=temp->next->next;
        delete valtodel;
    }
    void display(){
        Node *temp=head;
        if(!head){
            cout<<"nort";
        }
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

};
int main(){
    LinkedList list;
    list.insertAtHead(6);
    list.insertAtTail(7);
    list.insertAtTail(9);
    list.insertAtHead(99);
    list.insertAtHead(23);
    list.display();
    //list.deleteAtAnyIndex(23);
    list.display();
    //list.deleteAtHead();
    list.display();
    //list.deleteAtTail();
    list.display();
    list.reverseLinkedList();
    list.display();
    return 0;
}
