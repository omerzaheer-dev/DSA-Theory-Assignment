#include <iostream>
using namespace std;

void bubbleSort(int (&v)[5]) {
    int n = sizeof(v)/sizeof(v[0])-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main() {
    int v[5] = {5, 1, 4, 2, 8};
    bubbleSort(v);
    //for (auto i : v)
      //  cout << i << " ";

    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
