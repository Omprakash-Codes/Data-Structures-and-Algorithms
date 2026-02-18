/* You are given an array arr of non-negative integers, where each element represents the height of a block and each block has a width of 1.
Your task is to compute how much water can be trapped between the blocks after it rains.

Water can only be trapped in the valleys formed between taller blocks. 
The amount of water trapped at any position depends on the maximum height of blocks on both its left and right sides.

*/
int trapWater(vector<int>& arr) {
	//first method se solve kiye hai par 3 pass me hua hai
   /* int n=arr.size();
	vector<int>prefixmax(n);
	vector<int>suffixmax(n);
	prefixmax[0]=arr[0], suffixmax[n-1]=arr[n-1];
	for(int i=1;i<n;i++){
		prefixmax[i]=max(prefixmax[i-1],arr[i]);
	}
	for(int i=n-2;i>=0;i--){
		suffixmax[i]=max(suffixmax[i+1],arr[i]);
	}
	int totalwater=0;
	
	for(int i=1;i<n-1;i++){
		int minOfprefixsuffix=min(prefixmax[i-1],suffixmax[i+1]);
		if(minOfprefixsuffix>arr[i]){
			int sum=minOfprefixsuffix-arr[i];
			totalwater+=sum;
		}
	}
	return totalwater;*/
	// second method se 1 pass me solve kiya with the help of two pointer
	int n=arr.size();
	int leftmax=0,rightmax=0,left=0,right=n-1,totalwater=0;
	while(left<right){
		if(arr[left]<=arr[right]){
			if(arr[left]<leftmax){
				totalwater+=leftmax-arr[left];
			}else{
				leftmax=arr[left];
			}			
			left++;
		}else{
			if(arr[right]<rightmax){
				totalwater+=rightmax-arr[right];
			}else{
				rightmax=arr[right];
			}
			right--;
		}
	} 
	return totalwater;
}
