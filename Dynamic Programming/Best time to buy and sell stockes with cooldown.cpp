class Solution {
private:
int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>>& dp){
    if(ind>=n)return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        return dp[ind][buy] = max(-prices[ind]+f(ind+1,0,prices,n,dp),f(ind+1,1,prices,n,dp));
    }
    else{
        return dp[ind][buy] = max(prices[ind]+f(ind+2,1,prices,n,dp),f(ind+1,0,prices,n,dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        //memoisation
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,n,dp);


        //tabulation
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //no need to consider base cases;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];

    }

};
