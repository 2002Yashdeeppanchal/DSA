bool ispossible(int* arr,int n,int m,int mid){
        
        int stu=0;
        int pages=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>mid)return false;
            if(pages+arr[i]>mid){
                stu++;
                i--;
                pages=0;
            }
            else{
                pages+=arr[i];
            }
        }
        stu++;
        if(stu<=m){
            return true;
        }
        else{
            return false;
        }
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        int begin=INT_MAX;
        int over=0;
        
        for(int i=0;i<N;i++){
            begin=min(begin,arr[i]);
            over+=arr[i];
        }
        
        while(begin<=over){
            int mid=begin+(over-begin)/2;
            if(ispossible(arr,N,M,mid)){
                over=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        
        return begin;
        
    }
