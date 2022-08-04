https://leetcode.com/problems/find-the-duplicate-number/submissions/


idea is that our ans is lying between [1,n] inclusive so we try to make our mid as ans if we can we move over to mid-1 
  but how we cal the number of integers which are less than equal to mid is this cnt is greater so clearly we can observe that our ans is lieing between 1 to mid
  
  ex 1 2 4 5 7 7 7 7 8 9
  
  in this number of smaller than equal to 7 cnt is 8 
  
  visualise it deeply

int findDuplicate(vector<int>& nums) {
        
        int begin=1;
        int over=nums.size()-1;
        int cnt=0;
        
        while(begin<=over){
            int mid=begin+(over-begin)/2;
            cnt=0;
            for(auto i : nums){
                if(i<=mid)cnt++;
            }
            if(cnt<=mid){
                begin=mid+1;
            }
            else{
                over=mid-1;
            }
        }
        return begin;
    }
