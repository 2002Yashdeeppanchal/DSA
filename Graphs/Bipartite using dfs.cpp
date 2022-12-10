class Solution {
    
    private: 
    bool dfs(int node,vector<int>adj[],vector<int> &color,int kalar){
        color[node]=kalar;
        for(auto it : adj[node]){
            if(color[it]==-1){
                if(dfs(it,adj,color,!kalar)==false){
                    return false;
                }
            }
            else if(color[it]==kalar){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,adj,color,0)==false){
                    return false;
                }
            }
        }
        return true;
	}

};
