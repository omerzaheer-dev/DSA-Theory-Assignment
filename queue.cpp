#include <iostream>
using namespace std;

class Queue
{
public:
    int* arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int val)
    {
        if (rear == size - 1)
            cout << "Error: Queue is full" << endl;
        else
        {
            if (front == -1)
                front = 0;
            arr[++rear] = val;
        }
    }

    void dequeue()
    {
        if (front == -1)
            cout << "Error: Queue is empty" << endl;
        else
        {
            front++;
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        else
            return arr[front];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void display()
    {
        if (front == -1)
            cout << "Error: Queue is empty" << endl;
        else
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    cout << "Front element is " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(60);
    q.display();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}

