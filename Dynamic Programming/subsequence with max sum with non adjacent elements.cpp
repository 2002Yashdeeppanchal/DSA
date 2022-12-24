https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
int f(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0)return nums[0];
    if(ind<0)return 0;
    
    if(dp[ind]!=-1)return dp[ind];
    
    int pick=nums[ind] + f(ind-2,nums,dp);
    
    int notpick=0 + f(ind-1,nums,dp);
    
    return dp[ind]=max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    //memoisation
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
    
    //tabulation
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    int neg=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick+=dp[i-2];
        }
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
    
    
    //space optimisation
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick+=prev2;
        }
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
    
}
