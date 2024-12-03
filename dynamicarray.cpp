#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout<<"enter rows and columns"<<endl;
    cin>>m>>n;
    cout<<"enter first array"<<endl;
    int arr1[m][n], arr2[m][n], result[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr1[i][j];
        }
    }
    cout<<"enter second array"<<endl;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr2[i][j];
        }
    }
    cout<<"result"<<endl;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(arr1[i][j]==arr2[i][j])
                result[i][j]=arr1[i][j];
            else
                result[i][j]=0;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
