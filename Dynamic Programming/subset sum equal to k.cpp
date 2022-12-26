for recursion going n-1 to 0

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


for recursion going 0  -  n-1
which i master in recursion playlist
    
    
    
#include <bits/stdc++.h>

bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp,int n){
    if(ind>=n)return (target==0);
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool nottake=f(ind+1,target,arr,dp,n);
    bool take=false;
    if(arr[ind]<=target){
        take=f(ind+1,target-arr[ind],arr,dp,n);
    }
    return dp[ind][target] = take or nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
//     return f(0,k,arr,dp,n);
    
    //tabulation
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[n-1][arr[n-1]]=true;
    for(int ind=n-2;ind>=0;ind--){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind+1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind+1][target-arr[ind]];
            }
            dp[ind][target] = take or nottake;
         }
    }
    return dp[0][k];
}
