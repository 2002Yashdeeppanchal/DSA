#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    
//     printing the LIS (trace backing)
    int n=arr.size();
    vector<int>dp(n,1);
    vector<int>hash(n);
    int LISindex=0;
    int maxi=1;
    sort(arr.begin(),arr.end());
    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(arr[ind]%arr[prev_ind]==0 and dp[ind] < (1+dp[prev_ind])){
                dp[ind]=dp[prev_ind]+1;
                hash[ind]=prev_ind;
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                LISindex=ind;
            }
        }
    }
    vector<int>lds;
    lds.push_back(arr[LISindex]);
    while(hash[LISindex]!=LISindex){
        LISindex=hash[LISindex];
        lds.push_back(arr[LISindex]);
    }
    reverse(lds.begin(),lds.end());
//     for(auto &u : lis){
//         cout<<u<<" ";
//     }
//     cout<<endl<<endl;
    return lds;
    
}
