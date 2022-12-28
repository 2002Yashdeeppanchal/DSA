#include<bits/stdc++.h>

long int f(int ind,int t,int *a,vector<vector<long>> &dp){
    if(ind==0){
        return (t%a[0]==0);
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    long np=f(ind-1,t,a,dp);
    long p=0;
    if(a[ind]<=t)p=f(ind,t-a[ind],a,dp);
    
    return dp[ind][t] = p+np;
}


long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,0));
//     return f(n-1,value,a,dp);
    
    //tabulation
//     for(int t=0;t<=value;t++){
//         if(t%a[0]==0)dp[0][t]=1;
//         else dp[0][t]=0;
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int t=0;t<=value;t++){
//             long np=dp[ind-1][t];
//             long p=0;
//             if(a[ind]<=t)p=dp[ind][t-a[ind]];

//             dp[ind][t] = p+np;
//         }
//     }
//     return dp[n-1][value];
    
    
    vector<long>prev(value+1,0),curr(value+1);
    for(int t=0;t<=value;t++){
        if(t%a[0]==0)prev[t]=1;
        else prev[t]=0;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=value;t++){
            long np=prev[t];
            long p=0;
            if(a[ind]<=t)p=curr[t-a[ind]];

            curr[t] = p+np;
        }
        prev=curr;
    }
    return prev[value];
    
}
