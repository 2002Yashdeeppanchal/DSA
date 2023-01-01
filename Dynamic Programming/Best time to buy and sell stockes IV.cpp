#include <bits/stdc++.h>

int f(int ind,int transno,vector<int>& prices,int n,int k,vector<vector<int>>& dp){
    if(ind==n or transno==2*k)return 0;
    if(dp[ind][transno]!=-1)return dp[ind][transno];
    if(transno%2==0){//buy case
        return dp[ind][transno] = max(-prices[ind]+f(ind+1,transno+1,prices,n,k,dp),
                    f(ind+1,transno,prices,n,k,dp));
    }
    else{//sell
        return dp[ind][transno] = max(prices[ind]+f(ind+1,transno+1,prices,n,k,dp),
                   f(ind+1,transno,prices,n,k,dp));
        
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    //memoisation
//     vector<vector<int>>dp(n,vector<int>(2*k,-1));
//     return f(0,0,prices,n,k,dp);
    
    //tabulation
//     vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
//     //base cases are all 0 so no need to do that stuff
//     for(int ind=n-1;ind>=0;ind--){
//         for(int transno=2*k-1;transno>=0;transno--){
//             if(transno%2==0){//buy case
//                 dp[ind][transno] = max(-prices[ind]+dp[ind+1][transno+1],
//                             dp[ind+1][transno]);
//             }
//             else{//sell
//                 dp[ind][transno] = max(prices[ind]+dp[ind+1][transno+1],
//                            dp[ind+1][transno]);

//             }
//         }
//     }
//     return dp[0][0];
    
    
    //space optimisation
    vector<int>after(2*k+1,0);
    vector<int>curr(2*k+1,0);

    //base cases are all 0 so no need to do that stuff
    for(int ind=n-1;ind>=0;ind--){
        for(int transno=2*k-1;transno>=0;transno--){
            if(transno%2==0){//buy case
                curr[transno] = max(-prices[ind]+after[transno+1],
                            after[transno]);
            }
            else{//sell
                curr[transno] = max(prices[ind]+after[transno+1],
                           after[transno]);

            }
            after=curr;
        }
    }
    return after[0];
}
