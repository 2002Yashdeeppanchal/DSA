#include <bits/stdc++.h> 
bool ispossible(string &ind,string &prev){//ind string is the larger string
    if(prev.size()+1 != ind.size()){
        return false;
    }
    int first=0;
    int second=0;
    while(first<ind.size()){
        if(ind[first]==prev[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first==ind.size() and second==prev.size()){
        return true;
    }
    return false;
}

bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}


int longestStrChain(vector<string> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end(),comp);
    
//     Another method to solve this LIS
    vector<int>dp(n,1);
    int maxi=1;
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<=ind-1;prev_ind++){
            if(ispossible(arr[ind],arr[prev_ind])){
                dp[ind]=max(dp[ind],1+dp[prev_ind]);
            }
        }
        maxi=max(maxi,dp[ind]);
    }
    return maxi;
}
