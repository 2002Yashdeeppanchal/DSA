

int findPeakElement(vector<int>& arr) {
        
        int begin=1;//for starting from 0           think for  3 4 3 2 1 5 in this tc once mid is 0 then mid-1 create problem se take care for 0 index and last index seperately do this can ease for corner case like that if array contain only one element or two elements
        int end=arr.size()-2;
        
        int ans=0;
        
        if(arr.size()==1){
            return ans;
        }
        
        if(arr[0]>arr[1]){
            return ans;
        }
        if(arr[arr.size()-1]>arr[arr.size()-2]){
            return arr.size()-1;
        }
        
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            if(mid-1>=0 and mid+1<arr.size() and arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
                ans=mid;
                break;
            }
            if(mid-1>=0 and mid+1<arr.size() and arr[mid]>arr[mid-1] and arr[mid]<arr[mid+1]){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        
        
        return ans;
        
    }
