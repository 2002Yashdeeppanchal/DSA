class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>dist(1e5,1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        int mod=1e5;
        dist[start]=0;
        while(!q.empty()){
            int steps=q.front().first;
            int num=q.front().second;
            q.pop();
            if(num==end){
                return steps;
            }
            for(auto i : arr){
                int n=(num*i)%mod;
                if(steps+1<dist[n]){
                    dist[n]=steps+1;
                    q.push({steps+1,n});
                }
            }
        }
        return -1;
    }
};
