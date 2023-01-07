#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
// 	Another method to solve this LIS
    vector<int>dp1(n,1);
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<=ind-1;prev_ind++){
            if(arr[ind]>arr[prev_ind]){
                dp1[ind]=max(dp1[ind],1+dp1[prev_ind]);
            }
        }
    }	 
    
//     Another method to solve this LIS
    vector<int>dp2(n,1);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
            if(arr[ind]>arr[prev_ind]){
                dp2[ind]=max(dp2[ind],1+dp2[prev_ind]);
            }
        }
    }
    
    
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
} 
