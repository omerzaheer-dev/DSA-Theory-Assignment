#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int k) {
    k = k % size;
    int temp[size];
    for(int i = 0; i < size; i++) temp[i] = arr[(i + k) % size];
    for(int i = 0; i < size; i++) arr[i] = temp[i];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5, k = 2;
    rotateArray(arr, size, k);
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
