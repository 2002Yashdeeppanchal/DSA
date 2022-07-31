https://leetcode.com/problems/search-a-2d-matrix/submissions/

treet matrix as a sorted array

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int noofrows=matrix.size();
        int noofcol=matrix[0].size();
        
        int begin=0;
        int end=(noofrows*noofcol)-1;
        
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            if(matrix[mid/noofcol][mid%noofcol]<target){
                begin=mid+1;
            }
            else if(matrix[mid/noofcol][mid%noofcol]>target){
                end=mid-1;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
    




first search which row as to be searched and then search in that row


int rownumber(vector<vector<int>>& matrix,int target){
        
        int lo=0;
        int hi=matrix.size()-1;
        
        int colsize=matrix[0].size();
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[mid].back()<target){
                lo=mid+1;
            }
            else if(matrix[mid][0]>target){
                hi=mid-1;
            }
            else{
                return mid;
            }
        }
        
        return -1;
        
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=rownumber(matrix,target);
        
        if(row==-1){
            return false;
        }
        
        int colsz=matrix[0].size();
        
        int lo=0;
        int hi=colsz-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[row][mid]<target){
                lo=mid+1;
            }
            else if(matrix[row][mid]>target){
                hi=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
