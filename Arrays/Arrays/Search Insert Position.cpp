/* we have to find the target in sorted array if the target present return the index if not 
  return the index where it would be inserted in order to maintain the sorted order.
*/
int searchInsert(vector<int>& arr, int target) {
    // Your code here
	int n=arr.size();
	int start=0;
	int end=n-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(arr[mid]==target){
			return mid;
		}else if(arr[mid]>target){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	 return start;	
}
