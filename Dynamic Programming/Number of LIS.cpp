#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
//     Another method to solve this LIS
    int n=arr.size();
    vector<int>dp(n,1),cnt(n,1);
    int maxi=0;
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<=ind-1;prev_ind++){
            if(arr[ind]>arr[prev_ind] and dp[ind]<dp[prev_ind]+1){
                dp[ind]=dp[prev_ind]+1;
                cnt[ind]=cnt[prev_ind];
            }
            else if(arr[ind]>arr[prev_ind] and dp[ind]==dp[prev_ind]+1){
                cnt[ind]+=cnt[prev_ind];
            }
        }
        maxi=max(maxi,dp[ind]);
    }
    int nooflis=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)nooflis+=cnt[i];
    }
    return nooflis;
}
