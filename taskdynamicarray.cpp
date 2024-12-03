#include <iostream>
using namespace std;
class dynarr{
public:
int* array = nullptr;
int size = 0;
int capacity = 1;
void initializeArray(int initialCapacity = 1) {
    capacity = initialCapacity;
    size = 0;
    array = new int[capacity];
}
void growArray() {
    int* temp = new int[capacity+1];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    capacity+=1;
}
void shrinkArray() {
    capacity=size;
    int* temp = new int[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}
void push_back(int value) {
    if (size == capacity) {
        growArray();
    }
    array[size++] = value;
}
void pop_back() {
    if (size > 0) {
        array[size - 1] = 0;
        size--;
        shrinkArray();
    }
}
int search(int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}
void insertAt(int index, int value) {
    if (size == capacity) {
        growArray();
    }
    for (int i = size - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = value;
    size++;
}
void insertAtHead(int value) {
    if (size == capacity) {
        growArray();
    }
    for (int i = size - 1; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[0] = value;
    size++;
}
void insertAtTail(int value) {
    if (size == capacity) {
        growArray();
    }
    array[size] = value;
    size++;
}
void deleteAt(int index) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0;
    size--;
    shrinkArray();
}
void deleteAtTail() {
    array[size - 1] = 0;
    size--;
    shrinkArray();
}
void deleteAtHead() {
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0;
    size--;
    shrinkArray();
}
void printArrayDetails() {
    cout << "Elements of array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\nNo. of elements in array: " << size
    << ", Capacity of array: " << capacity << endl;
}
bool isEmpty() {
    return size == 0;
}
};
int main() {
    dynarr a1;
    a1.initializeArray();
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.insertAt(1,89);
    a1.printArrayDetails();
    a1.insertAtHead(14);
    a1.printArrayDetails();
    a1.insertAtTail(89);
    a1.printArrayDetails();
    a1.deleteAtHead();
    a1.printArrayDetails();
    a1.deleteAtTail();
    a1.printArrayDetails();
    int index = a1.search(1);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
