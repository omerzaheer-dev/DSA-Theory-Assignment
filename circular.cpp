#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
public:
    Node* head;
    CircularLinkedList()
    {
        head = nullptr;
    }

    void addNode(int val)
    {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int val)
    {
        if (head == nullptr)
            return;

        Node* temp = head;
        Node* prev = nullptr;
        if (head->data == val)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            else
            {
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                delete head;
                head = temp->next;
                return;
            }
        }
        while (temp->data != val && temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == val)
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    void displayList()
    {
        if (head == nullptr)
            return;

        Node* temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void searchNode(int val)
    {
        if (head == nullptr)
        {
            cout << "Error: List is empty." << endl;
            return;
        }

        Node* temp = head;
        do
        {
            if (temp->data == val)
            {
                cout << "Node " << val << " found." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << val << " not found." << endl;
    }

    void countNodes()
    {
        if (head == nullptr)
        {
            cout << "Error: List is empty." << endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        cout << "Number of nodes: " << count << endl;
    }
};

int main()
{
    CircularLinkedList cll;

    cll.addNode(1);
    cll.addNode(2);
    cll.addNode(3);
    cll.addNode(4);
    cll.addNode(5);

    cout << "Circular Linked List: ";
    cll.displayList();

    cll.deleteNode(3);
    cout << "After deleting node 3: ";
    cll.displayList();

    cll.searchNode(2);
    cll.searchNode(6);

    cll.countNodes();

    return 0;
}

