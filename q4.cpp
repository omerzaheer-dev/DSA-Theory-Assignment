#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int item) {
        data = item;
        next = nullptr;
    }
};

class orderedLinkedList {
private:
    Node* head;

public:
    orderedLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int item) {
        if(isItemPresent(item)) {
            cout << "Error: Item " << item << " already exists in the list.\n";
            return;
        }
        Node* newNode = new Node(item);
        if(isEmpty() || head->data >= item) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while(current->next != nullptr && current->next->data < item) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool isItemPresent(int item) {
        Node* current = head;
        while(current != nullptr) {
            if(current->data == item) return true;
            current = current->next;
        }
        return false;
    }

    void printList() {
        if(isEmpty()) {
            cout << "The list is empty.\n";
            return;
        }
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~orderedLinkedList() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    orderedLinkedList list;
    list.insert(10);
    list.insert(5);
    list.insert(15);
    list.insert(5);  // Duplicate, will show error
    list.insert(20);

    cout << "List elements: ";
    list.printList();

    return 0;
}
