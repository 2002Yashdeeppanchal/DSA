class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &v,int startrow,int startcol){
        vis[row][col]=1;
        
        int delrow[]={0,-1,+1,0};
        int delcol[]={-1,0,0,+1};
        
        int n=grid.size();
        int m=grid[0].size();
        
        v.push_back({row-startrow,col-startcol});
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,v,startrow,startcol);
            }
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        
        //traverse all the grid 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,grid,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
