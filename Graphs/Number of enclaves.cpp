class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 and grid[0][i]==1){
                vis[0][i]=1;
                q.push({0,i});
            }
            if(vis[n-1][i]==0 and grid[n-1][i]==1){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 and grid[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(vis[i][m-1]==0 and grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        
        int delrow[]={0,-1,+1,0};
        int delcol[]={-1,0,0,+1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};
