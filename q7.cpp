#include<iostream>
using namespace std;
int josephus(int n,int m){
int *arr=new int[n];
for(int i=0;i<n;i++)arr[i]=i+1;
int idx=0,remaining=n;
while(remaining>1){
idx=(idx+m-1)%remaining;
for(int i=idx;i<remaining-1;i++)arr[i]=arr[i+1];
remaining--;
}
int result=arr[0];
delete[] arr;
return result;
}
int main(){
int n,m;
cin>>n>>m;
cout<<josephus(n,m)<<endl;
}
