#include<bits/stdc++.h>

int f(int ind,int prev_ind,int arr[],int n,vector<vector<int>> &dp){
    if(ind==n)return 0;
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    int nottake = 0 + f(ind+1,prev_ind,arr,n,dp);
    int take=-1e8;
    if(prev_ind==-1 or arr[ind]>arr[prev_ind]){
        take = 1 + f(ind+1,ind,arr,n,dp);
    }
    return dp[ind][prev_ind+1] = max(take,nottake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    //memoisation
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));
//     return f(0,-1,arr,n,dp);
    
    
    //tabulation
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     for(int ind=n-1;ind>=0;ind--){
//         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
//             int nottake = 0 + dp[ind+1][prev_ind+1];
//             int take=-1e8;
//             if(prev_ind==-1 or arr[ind]>arr[prev_ind]){
//                 take = 1 + dp[ind+1][ind+1];
//             }
//             dp[ind][prev_ind+1] = max(take,nottake);
//         }
//     }
//     return dp[0][0];
    
    
    //space optimisation
//     vector<int>next(n+1,0),curr(n+1,0);
//     for(int ind=n-1;ind>=0;ind--){
//         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
//             int nottake = 0 + next[prev_ind+1];
//             int take=-1e8;
//             if(prev_ind==-1 or arr[ind]>arr[prev_ind]){
//                 take = 1 + next[ind+1];
//             }
//             curr[prev_ind+1] = max(take,nottake);
//         }
//         next=curr;
//     }
//     return next[0];
    
    
    
    
    
    //Another method to solve this LIS
//     vector<int>dp(n,1);
//     int maxi=1;
//     for(int ind=0;ind<n;ind++){
//         for(int prev_ind=0;prev_ind<=ind-1;prev_ind++){
//             if(arr[ind]>arr[prev_ind]){
//                 dp[ind]=max(dp[ind],1+dp[prev_ind]);
//             }
//         }
//         maxi=max(maxi,dp[ind]);
//     }
//     return maxi;
    
    
    
    
    
    //printing the LIS (trace backing)
    vector<int>dp(n,1);
    vector<int>hash(n);
    int LISindex=0;
    int maxi=1;
    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(arr[ind]>arr[prev_ind] and dp[ind] < (1+dp[prev_ind])){
                dp[ind]=dp[prev_ind]+1;
                hash[ind]=prev_ind;
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                LISindex=ind;
            }
        }
    }
    vector<int>lis;
    lis.push_back(arr[LISindex]);
    while(hash[LISindex]!=LISindex){
        LISindex=hash[LISindex];
        lis.push_back(arr[LISindex]);
    }
    reverse(lis.begin(),lis.end());
    for(auto &u : lis){
        cout<<u<<" ";
    }
    cout<<endl<<endl;
    return maxi;
}
