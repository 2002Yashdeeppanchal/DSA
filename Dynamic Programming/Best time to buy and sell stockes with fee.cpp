#include <bits/stdc++.h> 
int maximumProfit(int n, int fee, vector<int> &values) {
    //tabulation
    //here ind can be = n se declare a dp array so size n+1
    vector<long>ahead(2,0),curr(2);
    //base case
    ahead[0]=0;
    ahead[1]=0;
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit=max(-values[ind]+ahead[0],ahead[1]);
            }
            else{
                profit=max(values[ind]-fee+ahead[1],ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead=curr;
    }
    return ahead[1];
}
