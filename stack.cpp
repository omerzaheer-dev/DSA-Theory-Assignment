#include <iostream>
using namespace std;

class Stack
{
public:
    int* arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
            cout << "Error: Stack overflow" << endl;
        else
            arr[++top] = val;
    }

    void pop()
    {
        if (top == -1)
            cout << "Error: Stack underflow" << endl;
        else
            top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void display()
    {
        if (top == -1)
            cout << "Error: Stack is empty" << endl;
        else
        {
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    stack.display();

    cout << "Top element is " << stack.peek() << endl;

    stack.pop();
    stack.display();

    stack.push(60);
    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    return 0;
}

