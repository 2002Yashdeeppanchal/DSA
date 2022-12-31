#include <bits/stdc++.h> 

int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp){
    if(ind==n)return 0;
    if(cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    if(buy){
        return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),f(ind+1,1,cap,prices,n,dp));
    }
    else{
        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),f(ind+1,0,cap,prices,n,dp));
    }
}

int maxProfit(vector<int>& prices, int n)
{
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//     return f(0,1,2,prices,n,dp);
    
    //tabulation
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //since bases cases values are zero and we declare dp as all 0 so no need to do 
    //for base cases but for understanding we make notes in copy
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy==1){
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
