#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the last position of the list
    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete the node at the head of the list
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete a node with a specific value
    void deleteNodeByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }
        // If the node to be deleted is the head
        if (head->data == value) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete the last node of the list
    void deleteLastNode() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Search for a node by value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Insert at head
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    cout << "Linked List after inserting at head: ";
    list.display();

    // Insert at last
    list.insertAtLast(40);
    list.insertAtLast(50);
    cout << "Linked List after inserting at last: ";
    list.display();

    // Delete at head
    list.deleteAtHead();
    cout << "Linked List after deleting at head: ";
    list.display();

    // Delete a node by value
    list.deleteNodeByValue(40);
    cout << "Linked List after deleting node with value 40: ";
    list.display();

    // Delete the last node
    list.deleteLastNode();
    cout << "Linked List after deleting last node: ";
    list.display();

    // Search for a node
    int value = 50;
    if (list.search(value)) {
        cout << "Value " << value << " found in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Display final list
    cout << "Final Linked List: ";
    list.display();

    return 0;
}
