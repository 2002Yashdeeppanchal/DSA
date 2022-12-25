#include<bits/stdc++.h>
int mod=(int)(1e9+7);
int f(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
    if(i>=0 and j>=0 and mat[i][j]==-1)return 0;
    if(i==0 and j==0)return 1;
    if(i<0 or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=f(i-1,j,mat,dp);
    int left=f(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    //memoisation
    vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,mat,dp);
    
    
    //tabulation
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){
                dp[i][j]=0;
            }
            else if(i==0 and j==0)dp[i][j]=1;
            else{
                int left=0;
                int up=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
