#include <bits/stdc++.h>

int f(int ind,int tar,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(tar%num[0]==0)return tar/num[0];
        else return 1e9;
    }
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    int notpick=0 + f(ind-1,tar,num,dp);
    int pick=INT_MAX;
    if(num[ind]<=tar)pick=1 + f(ind,tar-num[ind],num,dp);
    
    return dp[ind][tar] = min(pick,notpick);
}

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
//     int ans = f(n-1,x,num,dp);
    
    //tabulation
//     for(int T=0;T<=x;T++){
//         if(T%num[0]==0)dp[0][T]=T/num[0];
//         else dp[0][T]=1e9;
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int tar=0;tar<=x;tar++){
//             int notpick=0 + dp[ind-1][tar];
//             int pick=INT_MAX;
//             if(num[ind]<=tar)pick=1 + dp[ind][tar-num[ind]];

//             dp[ind][tar] = min(pick,notpick);
//         }
//     }
//     int ans=dp[n-1][x];
//     if(ans>=1e9)return -1;
//     return ans;
    
    
    
    //tabulation
    vector<int>prev(x+1,0),curr(x+1);
    for(int T=0;T<=x;T++){
        if(T%num[0]==0)prev[T]=T/num[0];
        else prev[T]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=x;tar++){
            int notpick=0 + prev[tar];
            int pick=INT_MAX;
            if(num[ind]<=tar)pick=1 + curr[tar-num[ind]];

            curr[tar] = min(pick,notpick);
        }
        prev=curr;
    }
    int ans=prev[x];
    if(ans>=1e9)return -1;
    return ans;
}
