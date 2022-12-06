class Solution {
    private:
    bool check(int start,vector<int>adj[],vector<int> &color){
        queue<int>q;
        q.push(start);
        
        //start node color is to be let say 0
        color[start]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it : adj[node]){
                //if its neighbour is not colored yet then color it with different color
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                
                //if it is already colored then check its color with the node
                //as node is neighbour 
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    //initially all nodes are uncolored
	    vector<int>color(V,-1);
	    
	    //traverse whole graph this for loop is for connected component vala stuff
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
