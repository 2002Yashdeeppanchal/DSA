class Solution {
private:
    int timer=1;
private:
void dfs(int node,int parent,vector<int>adj[],vector<int> &vis,int tin[],int low[],vector<vector<int>> &bridges){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it : adj[node]){
        if(it == parent)continue;
        if(!vis[it]){
            dfs(it,node,adj,vis,tin,low,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node] or low[node] > tin[it]){
                bridges.push_back({node,it});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n,0);
        int tin[n];
        int low[n];

        vector<vector<int>>bridges;

        dfs(0,-1,adj,vis,tin,low,bridges);

        return bridges;


    }
};
