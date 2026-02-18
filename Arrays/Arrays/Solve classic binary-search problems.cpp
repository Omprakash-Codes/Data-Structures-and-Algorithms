/* <1>You are given an array arr[] of integers, where each element arr[i] represents the number of 
pages in the i-th book. You also have an integer k representing the number of students.

Your task is to allocate books to each student such that:

• Each student receives at least one book.

• Each student is assigned a contiguous sequence of books.
• No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words,
find the allocation arrangement where the student who receives the most pages has the smallest possible maximum.

Return the minimum possible maximum pages, or -1 if the allocation is not possible*/
bool pageAllocation(int maxpage,vector<int> &arr, int k){
	int count=1,pages=arr[0];
	for(int i=1;i<arr.size();i++){
		pages+=arr[i];
		if(pages>maxpage){
			count++;
			pages=arr[i];
		}
	}
	return count<=k;
}
int findPages(vector<int> &arr, int k) {
    // Your code here
	int n=arr.size();
	if(k>n){
		return -1;
	}
	int max=arr[0];
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(arr[i]>max){
			max=arr[i];
		}
	}
	int start=max;
	int end=sum;
	int res;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(pageAllocation(mid,arr,k)){
			end=mid-1;
			res=mid;
		}else{
			start=mid+1;
		}
	}
	return res;
}
/*<2>You are given an array arr[] where each element denotes the length of a board, and an integer krepresenting the number of painters available.

Each painter takes 1 unit of time to paint 1 unit length of a board.

Your task is to determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards.

The goal is to distribute the boards among painters such that the maximum time taken by any painter is minimized.
*/
int minTime(vector<int> &arr, int k) {
    // Your code here
	int n=arr.size();
	int max=arr[0];
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(arr[i]>max){
			max=arr[i];
		}
	}
	int start=max;
	int end=sum;
	int res;
	while(start<=end){
		int mid=start+(end-start)/2;
		int count=1,work=arr[0];
		for(int i=1;i<n;i++){
			work+=arr[i];
			if(work>mid){
				count++;
				work=arr[i];
			}
		}
		if(count<=k){
			end=mid-1;
			res=mid;
		}
		else{
			start=mid+1;
		}
	}
	return res;
}
