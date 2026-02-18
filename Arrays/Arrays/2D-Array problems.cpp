/*<1>You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
*/
void rotate(vector<vector<int>>& matrix) {
	//pahle matrix ko transpose karenge
    int row=matrix.size(),col=matrix[0].size();
	for(int i=0;i<row-1;i++){
		for(int j=i+1;j<col;j++){
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	//ab isko flip karenge
	int colstart=0,colend=col-1;
	while(colstart<colend){
	for(int i=0;i<row;i++){
		swap(matrix[i][colstart],matrix[i][colend]);
	}
	colstart++,colend--;
	}
}
/*<2>You are given an m x n integer matrix with the following two properties:

Each row is sorted in non-decreasing order
The first integer of each row is greater than the last integer of the previous row
Given an integer target, return true if target is in matrix or false otherwise.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowsize=matrix.size(),colsize=matrix[0].size();
	int start=0,end=rowsize*colsize-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		int rowindex=mid/colsize;
		int colindex=mid%colsize;
		if(matrix[rowindex][colindex]==target){
			return true;
		}else if(matrix[rowindex][colindex]>target){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return false;
}
