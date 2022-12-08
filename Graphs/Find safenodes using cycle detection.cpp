class Solution {
    
    private:
    bool dfs(int node,int vis[],int pathvis[],vector<int> adj[]){
      //phle aate hi node ka vis and pathvis 1 krdo
        vis[node]=1;
        pathvis[node]=1;
      
      
        for(auto it : adj[node]){
          //if its padosi is not vis then call 
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)){
                    return true;
                }
            }
          
          //if it is vis and its path vis is also 1 then this padosi is occuring twice in this path so without changing 
          //pathvis return
            else if(pathvis[it]){
                return true;
            }
        }
      
      //if all padosi are good and not form cycle or not directly connected to a cycle then pathvis ko 0 kro or chlo
        pathvis[node]=0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        
        int vis[v]={0};
        int pathvis[v]={0};
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj);
            }
        }
        
        vector<int> safenodes;
        
      //jin jin nodes ke pathvis 1 honge vo ans me ni aaenge
        for(int i=0;i<v;i++){
            if(!pathvis[i]){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
        
    }
};
