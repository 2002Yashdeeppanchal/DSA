#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &dp){
    if(i==0 and j==0)return 1;
    if(i<0 or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j]=up+left;
}
int uniquePaths(int m, int n) {
    //memoisation
    vector<vector<int>>dp(m,vector<int>(n,-1));
// 	return f(m-1,n-1,dp);
    
    //tabulation
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int up=0;
            int left=0;
            if(i==0 and j==0)continue;
            if(i>0)up=dp[i-1][j];
            if(j>0)left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
    
}
