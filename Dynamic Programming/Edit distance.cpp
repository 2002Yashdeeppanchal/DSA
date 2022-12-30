#include<bits/stdc++.h>

int f(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j])return dp[i][j] = f(i-1,j-1,str1,str2,dp);
    int inserting = 1 + f(i,j-1,str1,str2,dp);
    int remove = 1 + f(i-1,j,str1,str2,dp);
    int replace = 1 + f(i-1,j-1,str1,str2,dp);
    return dp[i][j] = min(inserting,min(remove,replace));
}

int fs(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    if(i==0)return j;
    if(j==0)return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i-1]==str2[j-1])return dp[i][j] = fs(i-1,j-1,str1,str2,dp);
    int inserting = 1 + fs(i,j-1,str1,str2,dp);
    int remove = 1 + fs(i-1,j,str1,str2,dp);
    int replace = 1 + fs(i-1,j-1,str1,str2,dp);
    return dp[i][j] = min(inserting,min(remove,replace));
}


int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();
    
    //memoisation
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,str1,str2,dp);
    
    
//     //tabulation
//     //shifting indexes by one
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
// //     return fs(n,m,str1,str2,dp);
    
//     for(int j=0;j<=m;j++){
//         dp[0][j]=j;
//     }
//     for(int i=0;i<=n;i++){
//         dp[i][0]=i;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
//             else{
//                  int inserting = 1 + dp[i][j-1];
//                  int remove = 1 + dp[i-1][j];
//                  int replace = 1 + dp[i-1][j-1];
//                  dp[i][j] = min(inserting,min(remove,replace));
//             }
//         }
//     }
//     return dp[n][m];
    
    
    
    
    //space optimisation
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++){
        prev[j]=j;
    }
//     for(int i=0;i<=n;i++){//this is that for each row the first col is 0
    //so this is already covered for the 0 index row(as we declare prev as all 0)
//         dp[i][0]=i;
//     }
    for(int i=1;i<=n;i++){
        curr[0]=i;//as for each row the first col is i itself
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) curr[j] = prev[j-1];
            else{
                 int inserting = 1 + curr[j-1];
                 int remove = 1 + prev[j];
                 int replace = 1 + prev[j-1];
                 curr[j] = min(inserting,min(remove,replace));
            }
        }
        prev=curr;
    }
    return prev[m];
    
    
    
 
}
