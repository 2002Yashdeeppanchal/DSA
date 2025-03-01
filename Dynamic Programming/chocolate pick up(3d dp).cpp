#include <bits/stdc++.h>

int f(int i,int j1,int j2,vector<vector<int>> &grid,int r,int c, vector<vector<vector<int>>> &dp){
    if(j1<0 or j1>=c or j2<0 or j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){//for A's movement B have 3 movement remember we move both A and B simultaneously
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2)value+=grid[i][j1];//take the curr cell value and then we move in next row
            else value+=grid[i][j1] + grid[i][j2];
            value+=f(i+1,j1+dj1,j2+dj2,grid,r,c,dp);
            maxi=max(maxi,value);//take max of all 9 combos
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    //dp[r][c][c]
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,grid,r,c,dp);
}
