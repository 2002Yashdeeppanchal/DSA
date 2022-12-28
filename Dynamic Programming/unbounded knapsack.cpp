#include <bits/stdc++.h> 

int f(int ind,int bagw,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){
    if(ind==0){
        return (bagw/weight[0]) * profit[0];
    }
    if(dp[ind][bagw]!=-1)return dp[ind][bagw];
    int notpick=0+ f(ind-1,bagw,profit,weight,dp);
    int pick=-1e8;
    if(weight[ind]<=bagw)pick=profit[ind] + f(ind,bagw-weight[ind],profit,weight,dp);
    
    return dp[ind][bagw] = max(pick,notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    int bagw=w;
//     return f(n-1,bagw,profit,weight,dp);
    
    
    //tabulation
//     for(int W=0;W<=bagw;W++){
//         dp[0][W]=(W/weight[0]) * profit[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int bagw=0;bagw<=w;bagw++){
//             int notpick=0+ dp[ind-1][bagw];
//             int pick=-1e8;
//             if(weight[ind]<=bagw)pick=profit[ind] + dp[ind][bagw-weight[ind]];

//             dp[ind][bagw] = max(pick,notpick);
//         }
//     }
//     return dp[n-1][bagw];
    
    
    //space optimisation
//     vector<int>prev(w+1),curr(w+1);    
//     for(int W=0;W<=bagw;W++){
//         prev[W]=(W/weight[0]) * profit[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int bagw=0;bagw<=w;bagw++){
//             int notpick=0+ prev[bagw];
//             int pick=-1e8;
//             if(weight[ind]<=bagw)pick=profit[ind] + curr[bagw-weight[ind]];

//             curr[bagw] = max(pick,notpick);
//         }
//         prev=curr;
//     }
//     return prev[bagw];
    
    
    
    //1d array optimisation
    vector<int>prev(w+1);    
    for(int W=0;W<=bagw;W++){
        prev[W]=(W/weight[0]) * profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int bagw=0;bagw<=w;bagw++){
            int notpick=0+ prev[bagw];
            int pick=-1e8;
            if(weight[ind]<=bagw)pick=profit[ind] + prev[bagw-weight[ind]];

            prev[bagw] = max(pick,notpick);
        }
    }
    return prev[bagw];
    
    
}
