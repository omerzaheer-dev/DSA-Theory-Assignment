#include <iostream>
using namespace std;
int binarySearch(int arr[],int size, int key){
    int start =0;
    int end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        cout<<mid<<" mid"<<endl;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,7,10,11,45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index=binarySearch(arr,size,2);
    if(index==-1) cout<<"elem not found"<<endl;
    else cout<<index<<" of elem ";
}
