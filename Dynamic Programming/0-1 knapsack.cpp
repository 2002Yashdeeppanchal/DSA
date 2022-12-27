#include <bits/stdc++.h> 

int f(int ind,int maxWeight,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp){
    if(ind==0){
        if(weight[0]<=maxWeight)return value[0];
        else return 0;
    }
    if(dp[ind][maxWeight]!=-1)return dp[ind][maxWeight];
    int pick=-1e8;
    if(weight[ind]<=maxWeight)
        pick=value[ind] + f(ind-1,maxWeight-weight[ind],weight,value,dp);
    int notpick=0 + f(ind-1,maxWeight,weight,value,dp);
    
    return dp[ind][maxWeight] = max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
//     return f(n-1,maxWeight,weight,value,dp);
    
    //tabulation
//     for(int wt=weight[0];wt<=maxWeight;wt++){
//         dp[0][wt]=value[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int maxW=0;maxW<=maxWeight;maxW++){
//             int pick=INT_MIN;
//             if(weight[ind]<=maxW)
//                 pick=value[ind] + dp[ind-1][maxW-weight[ind]];
//             int notpick=0 + dp[ind-1][maxW];

//             dp[ind][maxW] = max(pick,notpick);
//         }
//     }
//     return dp[n-1][maxWeight];    
    
    //space optimisation
//     vector<int>prev(maxWeight+1,0),curr(maxWeight+1);
//     for(int wt=weight[0];wt<=maxWeight;wt++){
//         prev[wt]=value[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int maxW=0;maxW<=maxWeight;maxW++){
//             int pick=INT_MIN;
//             if(weight[ind]<=maxW)
//                 pick=value[ind] + prev[maxW-weight[ind]];
//             int notpick=0 + prev[maxW];

//             curr[maxW] = max(pick,notpick);
//         }
//         prev=curr;
//     }
//     return prev[maxWeight];    
    
    
    
    //1D array space optimisation
    vector<int>prev(maxWeight+1,0);
    for(int wt=weight[0];wt<=maxWeight;wt++){
        prev[wt]=value[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int maxW=maxWeight;maxW>=0;maxW--){
            int pick=INT_MIN;
            if(weight[ind]<=maxW)
                pick=value[ind] + prev[maxW-weight[ind]];
            int notpick=0 + prev[maxW];

            prev[maxW] = max(pick,notpick);
        }
    }
    return prev[maxWeight];    
    
}
