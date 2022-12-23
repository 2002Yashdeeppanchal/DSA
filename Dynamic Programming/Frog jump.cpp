#include <bits/stdc++.h> 
int helper(int ind,vector<int> &heights,vector<int> &dp){
    if(ind==0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int left=helper(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right=helper(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
//     memoisation
    vector<int>dp(n+1,-1);
    int ans=helper(n-1,heights,dp);
    return ans;
    
    
//     tabulation
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i-1]-heights[i]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i-2]-heights[i]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
    
    //space optimise //as we need only two variables we dont need to create a whole array for this
    int prev=0;
    int sprev=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i-1]-heights[i]);
        int ss=INT_MAX;
        if(i>1){
            ss=sprev+abs(heights[i-2]-heights[i]);
        }
        int curr=min(ss,fs);
        sprev=prev;
        prev=curr;
    }
    return prev;
}
