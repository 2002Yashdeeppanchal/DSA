class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        if(source.first==destination.first and source.second==destination.second){
            return 0;
        }
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        
        int delrow[]={0,-1,+1,0};
        int delcol[]={+1,0,0,-1};
        
        while(!q.empty()){
            auto it = q.front();
            int row=it.second.first;
            int col=it.second.second;
            int dis=it.first;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1
                   and dis+1 < dist[nrow][ncol]){
                       dist[nrow][ncol]=dis+1;
                       if(nrow==destination.first and ncol==destination.second){
                           return (dis+1);
                       }
                       q.push({dis+1,{nrow,ncol}});
                   }
            }
        }
        
        return -1;
    }
};
