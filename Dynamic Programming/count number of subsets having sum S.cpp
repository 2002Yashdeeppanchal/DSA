#include <bits/stdc++.h> 

int f(int ind,int S,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(S==0 and num[0]==0)return 2;
        if(S==0 or S==num[0])return 1;
        return 0;
    }
    if(dp[ind][S]!=-1)return dp[ind][S];
    int notpick=f(ind-1,S,num,dp);
    int pick=0;
    if(num[ind]<=S)pick=f(ind-1,S-num[ind],num,dp);
    
    return dp[ind][S] = pick + notpick;
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
//     return f(n-1,tar,num,dp);
    
    //tabulation
    dp[0][0]=1;
    dp[0][num[0]]=1;
    if(num[0]==0)dp[0][0]=2;
//     if(num[0]==0)dp[0][0]=2;
//     else dp[0][0]=1;
//     if(num[0]!=0 and num[0]<=tar)dp[0][num[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notpick=dp[ind-1][sum];
            int pick=0;
            if(num[ind]<=sum)pick=dp[ind-1][sum-num[ind]];
            dp[ind][sum] = (pick + notpick)%mod;
        }
    }
    return dp[n-1][tar];
    
    //space optimisation
    vector<int>prev(tar+1,0),curr(tar+1);
    prev[0]=1;
    prev[num[0]]=1;
    if(num[0]==0)prev[0]=2;
//     if(num[0]==0)dp[0][0]=2;
//     else dp[0][0]=1;
//     if(num[0]!=0 and num[0]<=tar)dp[0][num[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notpick=prev[sum];
            int pick=0;
            if(num[ind]<=sum)pick=prev[sum-num[ind]];
            curr[sum] = (pick + notpick)%mod;
        }
        prev=curr;
    }
    return prev[tar];
    
}
