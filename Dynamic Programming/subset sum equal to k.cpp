#include <bits/stdc++.h>

bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(ind<0)return (target==0);
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool nottake=f(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target] = take or nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //memoisation
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
//     return f(n-1,k,arr,dp);
    
    //tabulation
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = take or nottake;
        }
    }
    return dp[n-1][k];
    
    
}
