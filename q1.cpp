#include <iostream>
using namespace std;

void generateRandomList(int list[],int size){
    for(int i = 0; i < size; i++) list[i] = rand() % 10000;
}
void sortList(int list[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int size, int target, int &comparisons) {
    int left = 0, right = size - 1;
    while(left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int sequentialSearch(int arr[], int size, int target, int &comparisons) {
    for(int i = 0; i < size; i++) {
        comparisons++;
        if(arr[i] == target) return i;
    }
    return -1;
}
int binarySearchWithSwitch(int arr[], int size, int target, int &comparisons) {
    if(size < 15) return sequentialSearch(arr, size, target, comparisons);
    return binarySearch(arr, size, target, comparisons);
}
int main() {
    int list[1000];
    generateRandomList(list, 1000);
    sortList(list, 1000);
    int comparisonsBinary = 0, comparisonsHybrid = 0;
    int target = list[rand() % 1000];
    int resultBinary = binarySearch(list, 1000, target, comparisonsBinary);
    int resultHybrid = binarySearchWithSwitch(list, 1000, target, comparisonsHybrid);
    cout << "Binary search comparisons: " << comparisonsBinary;
    if(resultBinary != -1) cout << ", Position: " << resultBinary;
    cout << "\nHybrid search comparisons: " << comparisonsHybrid;
    if(resultHybrid != -1) cout << ", Position: " << resultHybrid;
    cout << endl;
    return 0;
}
