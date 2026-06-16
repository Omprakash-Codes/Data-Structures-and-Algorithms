// Topic: Heap Sort
// Approach:
// Build Max Heap + Repeated Heapify
// Description:
// Sort an array using Heap Sort.
// First, build a Max Heap from the array.
// Then repeatedly place the maximum element
// at the end of the array and restore the
// heap property for the remaining elements.
// Time Complexity:
// Best Case    : O(N log N)
// Average Case : O(N log N)
// Worst Case   : O(N log N)
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
void heapsort(int arr[],int n){
   for(int i=n-1;i>0;i--){
      swap(arr[0],arr[i]);
      heapyfy(arr,0,i-1);
   }  
}
int main(){
    int arr[]={12,13,8,10,14,18,17};
    buildMaxheap(arr,7);
    heapsort(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
