#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
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
        Node* prev = nullptr;
        Node* current = head;
        head = head->next;

        while (current != nullptr && current->next != nullptr) {
            Node* nextNode = current->next;
            Node* nextNextNode = nextNode->next;
            nextNode->next = current;
            current->next = nextNextNode;
            if (prev != nullptr) {
                prev->next = nextNode;
            }
            prev = current;
            current = nextNextNode;
        }
    }

    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
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
