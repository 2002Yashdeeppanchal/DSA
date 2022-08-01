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
        return arr[end];
    }
