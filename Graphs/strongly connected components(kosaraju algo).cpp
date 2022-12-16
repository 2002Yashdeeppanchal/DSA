
class Solution
{
    private:
    void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    private:
    void dfs2(int node,vector<int> revadj[],vector<int> &vis){
        vis[node]=1;
        for(auto it : revadj[node]){
            if(!vis[it]){
                dfs2(it,revadj,vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
      //sort all the nodes with their finishing time
	    //O(v+E)
        vector<int> vis(v,0);
        stack<int>st;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
      //reverse the graph
	    //O(v+e)
        vector<int> revadj[v];
        for(int i=0;i<v;i++){
            for(auto it : adj[i]){
                revadj[it].push_back(i);
            }
        }
        
      
      //vis can be reused for further dfs
        for(int i=0;i<v;i++){
            vis[i]=0;
        }
        
      
      //do simple dfs
	    //O(v+e)
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(vis[node]==1){
                continue;
            }
            scc++;
            dfs2(node,revadj,vis);
        }
        
        return scc;
        
    }
};
