#include <bits/stdc++.h> 

int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j<0 or j>=matrix[0].size())return -1e9;
    if(i==0)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int up=matrix[i][j] + f(i-1,j,matrix,dp);
    int ld=matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rd=matrix[i][j] + f(i-1,j+1,matrix,dp);
    
    return dp[i][j] = max(up,max(ld,rd));
    
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>>dp(n,vector<int>(m,-1));
//     for(int i=0;i<m;i++){
//         maxi=max(maxi,f(n-1,i,matrix,dp));
//     }
//     return maxi;
    
    //tabulation
    for(int i=0;i<m;i++){
        dp[0][i]=matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j] + dp[i-1][j];
            int ld=-1e9;
            int rd=-1e9;
            if(j-1>=0)    ld=matrix[i][j] + dp[i-1][j-1];    
            if(j+1<m)     rd=matrix[i][j] + dp[i-1][j+1];
            
            dp[i][j]=max(ld,max(up,rd));
        }
    }
    maxi=-1e9;
    for(int i=0;i<m;i++){
        maxi=max(maxi,dp[n-1][i]);
    }
    return maxi;
    
    
    
    //space optimisation
    vector<int>prev(m);
    for(int i=0;i<m;i++){
        prev[i]=matrix[0][i];
    }
    vector<int>curr(m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j] + prev[j];
            int ld=-1e9;
            int rd=-1e9;
            if(j-1>=0)    ld=matrix[i][j] + prev[j-1];    
            if(j+1<m)     rd=matrix[i][j] + prev[j+1];
            
            curr[j]=max(ld,max(up,rd));
        }
        prev=curr;
    }
    maxi=-1e9;
    for(int i=0;i<m;i++){
        maxi=max(maxi,prev[i]);
    }
    return maxi;
    
    
}
