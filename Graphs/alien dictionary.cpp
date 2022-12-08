class Solution{
    private:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
    
    //get the indegree ready
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    
	    vector<int>ans;
    
    //jinki indegree 0 hai unko q me 
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
        //is node se connected nodes ki indegree -- krdo
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return ans;
	}
    public:
    string findOrder(string dict[], int n, int K) {
        
      //adjacency matrix
        vector<int>adj[K];
        for(int i=0;i<n-1;i++){
            string str1=dict[i];
            string str2=dict[i+1];
            int len=min(str1.size(),str2.size());
          //getting the first mismaching char and create a edge between them
            for(int ptr=0;ptr<len;ptr++){
                if(str1[ptr]!=str2[ptr]){
                    adj[str1[ptr]-'a'].push_back(str2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int>topo=topoSort(K,adj);
        
        string ans;
        
        for(auto i : topo){
            ans.push_back(i+'a');
        }
        
        
        return ans;
        
    }
};
