https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

idea is that we simply increase our windown till we reach sum>=target then store in ans then we try to decrease our window size by increase i till our window 
sum>=target then repeat 



int minSubArrayLen(int target, vector<int>& v) {
        
        int i=0;
        int j=0;
        
        int n=v.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        if(sum<target)return 0;
        sum=0;
        
        int ans=INT_MAX;
        
        while(j<n){
            
            sum+=v[j];
            
            if(sum<target){
                j++;
            }
            
            else if(sum>=target){
                
                while(sum>=target){
                    ans=min(ans,j-i+1);
                    sum-=v[i];
                    i++;
                }
                j++;
                
            }
        }
        
        
        return ans;
        
    }
