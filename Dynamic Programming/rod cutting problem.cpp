#include<bits/stdc++.h>

int f(int ind,int n,vector<int> &price,vector<vector<int>> &dp){
    if(ind==0){
        return (n*price[0]);
    }
    if(dp[ind][n]!=-1)return dp[ind][n];
    int np=0 + f(ind-1,n,price,dp);
    int p=INT_MIN;
    int rodlength=ind+1;
    if(rodlength<=n)p=price[ind] + f(ind,n-rodlength,price,dp);
    
    return dp[ind][n]=max(p,np);
}

int cutRod(vector<int> &price, int n)
{
    
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    int sz=price.size();
// 	return f(sz-1,n,price,dp);
    
    //tabulation
//     for(int N=0;N<=n;N++){
//         dp[0][N]=N*price[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int N=0;N<=n;N++){
//             int np=0 + dp[ind-1][N];
//             int p=INT_MIN;
//             int rodlength=ind+1;
//             if(rodlength<=N)p=price[ind] + dp[ind][N-rodlength];

//             dp[ind][N]=max(p,np);
//         }
//     }
//     return dp[sz-1][n];
    
    
    
    //space optimisation
//     vector<int>prev(n+1),curr(n+1);
//     for(int N=0;N<=n;N++){
//         prev[N]=N*price[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int N=0;N<=n;N++){
//             int np=0 + prev[N];
//             int p=INT_MIN;
//             int rodlength=ind+1;
//             if(rodlength<=N)p=price[ind] + curr[N-rodlength];

//             curr[N]=max(p,np);
//         }
//         prev=curr;
//     }
//     return prev[n];
    
    
    //1d array space optimisation
    vector<int>prev(n+1);
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int np=0 + prev[N];
            int p=INT_MIN;
            int rodlength=ind+1;
            if(rodlength<=N)p=price[ind] + prev[N-rodlength];

            prev[N]=max(p,np);
        }
    }
    return prev[n];
    
}
