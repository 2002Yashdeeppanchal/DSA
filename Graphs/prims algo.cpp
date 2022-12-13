class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        
        //as we are concern about the sum only we store wt and node in pq
        //if we have asked to create mst then we keep track of parent node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        vector<int>vis(v,0);
        int sum=0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum+=wt;
            for(auto it : adj[node]){
                int adjnode=it[0];
                int ewt=it[1];
                if(!vis[adjnode]){
                    pq.push({ewt,adjnode});
                }
            }
        }
        return sum;
    }
};
