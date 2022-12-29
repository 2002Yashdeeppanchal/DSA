#include <bits/stdc++.h> 
int lcs(string &s, string &t){
    int n=s.size();
    int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     return fs(n,m,s,t,dp);
    
    //if ind1 is 0 then ind2 is anything
    for(int ind2=0;ind2<=m;ind2++){
        dp[0][ind2]=0;
    }
    //if ind2 is 0 then ind1 is anything
    for(int ind1=0;ind1<=n;ind1++){
        dp[ind1][0]=0;
    }
    int ans=0;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s[ind1-1]==t[ind2-1]){
                dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                ans=max(ans,dp[ind1][ind2]);
            }

            else dp[ind1][ind2] = 0;
        }
    }
    return ans;
    
}
