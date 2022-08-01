https://leetcode.com/problems/search-a-2d-matrix-ii/

at every iteration we cancel out a row or a col so search space is redueced;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=0;
        int col=m-1;
        
        while(row<n and col>=0){
            
            if(matrix[row][col]==target)return true;
            
            if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
