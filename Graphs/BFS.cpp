vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        queue<int>q;
        q.push(0);
        
        vector<int>visited(v,0);
        visited[0]=1;
        
        vector<int>bfs;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i : adj[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        
        return bfs;
    }
