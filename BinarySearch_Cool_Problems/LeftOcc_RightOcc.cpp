bool is_exist(vector<int>v,int k){
        int begin=0;
        int end=v.size()-1;
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            if(v[mid]==k){
                return true;
            }
            else if(v[mid]<k){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    
    
    int lowerbound(vector<int>v,int k){
    int begin=0;
    int end=v.size()-1;
    int ans=0;
    while(begin<=end){
        int mid=begin+(end-begin)/2;
        if(v[mid]<k){
            begin=mid+1;
        }
        else{
            end=mid-1;
            ans=mid;
        }
    }
    return ans;
}

int upperbound(vector<int>v,int k){
    int begin=0;
    int end=v.size()-1;
    int ans=0;
    while(begin<=end){
        int mid=begin+(end-begin)/2;
        if(v[mid]<=k){
            ans=mid;
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        if(!is_exist(nums,target)){
            ans[0]=-1;
            ans[1]=-1;
            return ans;
        }
        int leftocc=lowerbound(nums,target);
        int rightocc=upperbound(nums,target);
        ans[0]=leftocc;
        ans[1]=rightocc;
        return ans;
    }
