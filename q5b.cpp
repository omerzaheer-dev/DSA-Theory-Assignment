#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
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

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void swapAdjacent() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            Node* nextNode = current->next;
            Node* nextNextNode = nextNode->next;
            current->next = nextNextNode;
            if (nextNextNode != nullptr) {
                nextNextNode->prev = current;
            }
            nextNode->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = nextNode;
            }
            nextNode->next = current;
            current->prev = nextNode;
            current = nextNextNode;
        }
        head = head->next;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: ";
    list.printList();

    list.swapAdjacent();

    cout << "List After Swapping Adjacent Nodes: ";
    list.printList();

    return 0;
}
