int findMin(vector<int>& arr) {
        
        int begin=0;
        int end=arr.size()-1;
        
        if(arr[0]<=arr[arr.size()-1]){
            return arr[0];
        }
        
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            if(arr[mid]>=arr[0]){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        end++;
        return end;
    }
    
    int indoftarget(vector<int>&arr,int start,int over,int target){
        
        int begin=start;
        int end=over;
        
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]<target){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& arr, int target) {
        
        int pivotind=findMin(arr);
        
        int start=0;
        int over=0;
        
        if(arr[0]<=arr[arr.size()-1]){
            start=0;
            over=arr.size()-1;
            return indoftarget(arr,start,over,target);
        }
        
        if(arr[0]<=target and arr[pivotind-1]>=target){
            start=0;
            over=pivotind-1;
            return indoftarget(arr,start,over,target);
        }
        if(arr[pivotind]<=target and arr[arr.size()-1]>=target){
            start=pivotind;
            over=arr.size()-1;
            return indoftarget(arr,start,over,target);
        }
        return -1;
        
    }
