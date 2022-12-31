#include<bits/stdc++.h>

bool f(int i,int j,string &pattern,string &text,vector<vector<int>>& dp){
    //base cases
    if(i<0 and j<0)return true;
    if(i<0 and j>=0)return false;
    if(i>=0 and j<0){
        for(int ii=0;ii<=i;ii++){
            if(pattern[ii]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    //explore
    if(pattern[i]==text[j] or pattern[i]=='?'){
        return dp[i][j] = f(i-1,j-1,pattern,text,dp);
    }
    else if(pattern[i]=='*'){
        return dp[i][j] = f(i-1,j,pattern,text,dp) or f(i,j-1,pattern,text,dp);
    }
    else{
        return dp[i][j] = false;
    }
}


bool fs(int i,int j,string &pattern,string &text,vector<vector<int>>& dp){
    //base cases
    if(i==0 and j==0)return true;
    if(i==0 and j>0)return false;
    if(i>0 and j==0){
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    //explore
    if(pattern[i-1]==text[j-1] or pattern[i-1]=='?'){
        return dp[i][j] = fs(i-1,j-1,pattern,text,dp);
    }
    else if(pattern[i-1]=='*'){
        return dp[i][j] = fs(i-1,j,pattern,text,dp) or fs(i,j-1,pattern,text,dp);
    }
    else{
        return dp[i][j] = false;
    }
}




bool wildcardMatching(string pattern, string text)
{
    int n=pattern.size();
    int m=text.size();
    
    //memoisation
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,pattern,text,dp);
    
    
//     //for tabulation convert all the indexes as indexes+1
//     vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
// //     return fs(n,m,pattern,text,dp);
//     dp[0][0]=true;
//     for(int j=1;j<=m;j++){
//         dp[0][j]=false;
//     }
//     for(int i=1;i<=n;i++){
//         bool flag=true;
//         for(int ii=1;ii<=i;ii++){
//             if(pattern[ii-1]!='*'){
//                 flag=false;
//                 break;
//             }
//         }
//         dp[i][0]=flag;
//     }
    
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(pattern[i-1]==text[j-1] or pattern[i-1]=='?'){
//                 dp[i][j] = dp[i-1][j-1];
//             }
//             else if(pattern[i-1]=='*'){
//                 dp[i][j] = dp[i-1][j] or dp[i][j-1];
//             }
//             else{
//                 dp[i][j] = false;
//             }
//         }
//     }
//     return dp[n][m];
    
    
    
    
    
    
    //space optimisation
    //for tabulation convert all the indexes as indexes+1
    vector<bool>prev(m+1,false),curr(m+1,false);
    //     return fs(n,m,pattern,text,dp);
    prev[0]=true;
    for(int j=1;j<=m;j++){
        prev[j]=false;
    }
//     for(int i=1;i<=n;i++){
//         bool flag=true;
//         for(int ii=1;ii<=i;ii++){
//             if(pattern[ii-1]!='*'){
//                 flag=false;
//                 break;
//             }
//         }
//         dp[i][0]=flag;
//     }
    
    for(int i=1;i<=n;i++){
        //curr's 0th col is to be update in every iteration
        bool flag=true;
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*'){
                flag=false;
                break;
            }
        }
        curr[0]=flag;
        for(int j=1;j<=m;j++){
            if(pattern[i-1]==text[j-1] or pattern[i-1]=='?'){
                curr[j] = prev[j-1];
            }
            else if(pattern[i-1]=='*'){
                curr[j] = prev[j] or curr[j-1];
            }
            else{
               curr[j] = false;
            }
        }
        prev=curr;
    }
    return prev[m];
}

