// Topic: Build Max Heap from Array
// Approach:
// Construction (Step-Down Heapify)
// Description:
// Convert an unsorted array into a Max Heap
// by applying heapify from the last non-leaf
// node up to the root.
// Heap Property:
// Parent Node >= Child Nodes
// Time Complexity:
// O(N)
// Space Complexity:
// O(1)
#include<iostream>
using namespace std;
void heapyfy(int arr[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapyfy(arr,largest,n);
    }
}
void buildMaxheap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapyfy(arr,i,n);
    }
}
int main(){
    int arr[]={12,13,8,10,14,18,17};
    buildMaxheap(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
