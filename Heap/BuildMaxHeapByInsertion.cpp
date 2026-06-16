// Problem: Build Max Heap by Inserting Elements One by One
// Approach: Bottom-Up Heapify (Step-Up)
// Description:
// Insert elements one by one into a Max Heap.
// After every insertion, move the element
// upward until the Max Heap property is restored.
// Time Complexity:
// Each Insertion : O(log N)
// Building Heap  : O(N log N)
// Space Complexity: O(N)
#include<iostream>
using namespace std;
class maxheap{
    public:
    int *arr;
    int index;
    int size;
    maxheap(int n){
        arr=new int[n];
        size=n;
        index=0;
    }
    void insert(int val){
        if(index==size){
            cout<<"heap overflow!"<<endl;
            return;
        }
        if(index==0){
            arr[index]=val;
            cout<<arr[index]<<"-inserted "<<endl;
            index++;
            return;
        }
        arr[index]=val; 
        int i=index;
        index++;
        while(i>0 && arr[i]>arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
        cout<<arr[i]<<"-inserted "<<endl;
    }
    void heapyfy(int i){
        int largest=i;
        int left=i*2+1;
        int right=i*2+2;
        if(left<index && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<index && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapyfy(largest);
        }
    }
    void Delete(){
        if(index==0){
            cout<<"heap underflow\n";
            return;
        }
        if(index==1){
            cout<<arr[0]<<"-deleted!\n";
            index--;
            return;
        }
        cout<<arr[0]<<"-deleted!\n";
        arr[0]=arr[index-1];
        index--;
        heapyfy(0);
    }
    void print(){
        for(int i=0;i<index;i++){
            cout<<arr[i]<<" "<<endl;
        }
    }

};
int main(){
    maxheap h(6);
    for(int i=0;i<6;i++){
        int n;
        cin>>n;
        h.insert(n);
    }
    h.print();
    h.Delete();
    h.print();
    return 0;
}
