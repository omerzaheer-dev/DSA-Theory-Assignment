#include <iostream>
#include <unordered_map>
using namespace std;

void findDuplicates(int arr[], int size) {
    unordered_map<int, int> freq;
    for(int i = 0; i < size; i++) freq[arr[i]]++;
    for(auto &entry : freq) {
        if(entry.second > 1) cout << "Element " << entry.first << " occurs " << entry.second << " times.\n";
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 6, 3, 2};
    int size = 9;
    findDuplicates(arr, size);
    return 0;
}
