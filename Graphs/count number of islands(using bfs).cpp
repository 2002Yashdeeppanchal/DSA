class Solution {
    private:
        void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
            
            int n=grid.size();
            int m=grid[0].size();
            
            queue<pair<int,int>>q;
            q.push(make_pair(row,col));
            
            vis[row][col]=1;
            
            while(!q.empty()){
                
                int r=q.front().first;
                int c=q.front().second;
                
                q.pop();
                
                for(int delr=-1;delr<=1;delr++){
                    for(int delc=-1;delc<=1;delc++){
                        int nrow=r+delr;
                        int ncol=c+delc;
                        if(nrow<n and ncol<m and nrow>=0 and ncol>=0 and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                            vis[nrow][ncol]=1;
                            q.push(make_pair(nrow,ncol));
                        }
                    }
                }
                
            }
            
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==0){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        
        
        return cnt;
        
        
    }
};
