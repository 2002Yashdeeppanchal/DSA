the intution is that we try to expand our size of window okay
so we increase the size till the number of zeros in our window crosses the barrier
if it crosses we try for different window so we increase begin pointer to remove the extra zero so that our window still have K zeros


int longestOnes(vector<int>& nums, int k) {
        
        int begin=0;
        int end=0;
        
        int zerocnt=0;
        
        int max_window=INT_MIN;
        
        for(end=0;end<nums.size();end++){
            if(nums[end]==0){
                zerocnt++;
            }
            while(zerocnt>k){
                if(nums[begin]==0){
                    zerocnt--;
                }
                begin++;
            }
            max_window=max(max_window,end-begin+1);
        }
        return max_window;
    }
