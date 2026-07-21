// Problem: Merge Two Binary Max Heaps
// Approach:
// Merge Arrays + Build Max Heap (Bottom-Up Heapify)
// Description:
// Merge two binary max heaps into a single
// valid max heap by combining both arrays
// and applying bottom-up heap construction.
// Time Complexity:
// O(N + M)
// Space Complexity:
// O(N + M)
void heapify(vector<int>&arr,int s,int index){
    int maxelement=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<s && arr[left]>arr[maxelement]){
        maxelement=left;
    }
    if(right<s && arr[right]>arr[maxelement]){
        maxelement=right;
    }
    if(maxelement!=index){
        swap(arr[index],arr[maxelement]);
        heapify(arr,s,maxelement);
    }
}
void buildheap(vector<int>&arr,int s){
    for(int i=s/2-1;i>=0;i--){
        heapify(arr,s,i);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // Your code here
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
    }
    for(int i=0;i<m;i++){
        ans.push_back(b[i]);
    }
    int size=n+m;
    buildheap(ans,size);
    return ans;
}
