#include <bits/stdc++.h> 

int f(int i,int j,vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
    if(i==n-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int down=triangle[i][j] + f(i+1,j,triangle,n,dp);
    int diagonal=triangle[i][j] + f(i+1,j+1,triangle,n,dp);
    return dp[i][j] = min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    //memoisation
    vector<vector<int>>dp(n,vector<int>(n,-1));
	return f(0,0,triangle,n,dp);
    
    
    //tabulation
    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j] + dp[i+1][j];
            int diagonal=triangle[i][j] + dp[i+1][j+1];
            dp[i][j]=min(down,diagonal);
        }
    }
    return dp[0][0];
    
    
    //space optimisation
    vector<int>forw(n,0);
    for(int i=0;i<n;i++){
        forw[i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        vector<int>curr(n);
        for(int j=i;j>=0;j--){
            int down=triangle[i][j] + forw[j];
            int diagonal=triangle[i][j] + forw[j+1];
            curr[j]=min(down,diagonal);
        }
        forw=curr;
    }
    return forw[0];
}
