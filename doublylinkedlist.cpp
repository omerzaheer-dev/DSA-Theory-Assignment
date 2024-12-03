#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;

        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    void deleteFront() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteNode(Node* node) {
        if (!node) return;

        if (node == head) {
            deleteFront();
            return;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        delete node;
    }

    void displayForward() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    Node* search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            deleteFront();
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    list.insertEnd(40);
    list.insertEnd(50);

    cout << "Display list from front to back: ";
    list.displayForward();

    cout << "Display list from back to front: ";
    list.displayBackward();

    Node* node = list.search(20);
    if (node) {
        cout << "Node with value 20 found!" << endl;
    } else {
        cout << "Node with value 20 not found!" << endl;
    }

    node = list.search(10);
    if (node) {
        list.insertAfter(node, 25);
    }

    cout << "List after inserting 25 after 10: ";
    list.displayForward();

    list.deleteFront();
    list.deleteEnd();

    cout << "List after deleting front and end: ";
    list.displayForward();

    return 0;
}
