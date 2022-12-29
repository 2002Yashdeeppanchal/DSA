int lcs(string s, string t)
{
	int n=s.size();
    int m=t.size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,s,t,dp);
    
    
    
    //tabulation
    //if we shift ind by plus 1
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
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s[ind1-1]==t[ind2-1]) dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];

            else dp[ind1][ind2] = 0 + max( dp[ind1-1][ind2],dp[ind1][ind2-1] );
        }
    }
//     return dp[n][m];
    
    
    
    
    //space optimisation
    //same prev and curr concept
    
    string lcs="";
    for(int i=0;i<dp[n][m];i++){
        lcs+='$';
    }
    int index=lcs.size()-1;
    int i=n;
    int j=m;
    
    while(i>0 and j>0){
        if(s[i-1]==t[j-1]){
            lcs[index]=s[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<lcs;
    
    
    
}
