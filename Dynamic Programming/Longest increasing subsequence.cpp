#include<bits/stdc++.h>

int f(int ind,int prev_ind,int arr[],int n,vector<vector<int>> &dp){
    if(ind==n)return 0;
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    int nottake = 0 + f(ind+1,prev_ind,arr,n,dp);
    int take=-1e8;
    if(prev_ind==-1 or arr[ind]>arr[prev_ind]){
        take = 1 + f(ind+1,ind,arr,n,dp);
    }
    return dp[ind][prev_ind+1] = max(take,nottake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));//n+1 because ind can be -1 so index shifting
    return f(0,-1,arr,n,dp);
}
