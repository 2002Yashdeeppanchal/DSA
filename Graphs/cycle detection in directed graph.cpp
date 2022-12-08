class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V]={0};
    
    //get the indegree ready
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    
	    int cnt=0;
    
    //jinki indegree 0 hai unko q me 
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
        //is node se connected nodes ki indegree -- krdo
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    if(cnt==V){
	        return false;
	    }
	    return true;
    }
};
