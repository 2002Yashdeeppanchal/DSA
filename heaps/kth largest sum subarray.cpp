#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	                    priority_queue<int,vector<int>,greater<int>>pq;
        
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
          //if p ka size k se chota hai to daalte jao
            if(pq.size()<k){
                pq.push(sum);
            }
            else{
              //agr curr sum bda hai till smallest se to push krdo
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    
    return pq.top();
}
