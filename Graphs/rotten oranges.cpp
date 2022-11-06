class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //first put all the rotten oranges in the queue
        queue<pair<pair<int,int>,int>> q;  //{{row,col},time}
        
      //keep a freshcnt then at  last we compare this freshcnt and another fresh cnt if they are equal then we rot all fresh ones
      //if not then there is at least one fresh left
        int freshcnt=0;
        
        
        int vis[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    freshcnt++;
                }
            }
        }
        
        int delrow[]={0,-1,0,1};
        int delcol[]={1,0,-1,0};
        
        int maxtime=0;
        int cnt=0;
        
      
      // in q we insert a fresh one then its neightbours and so on firstly q initially contain only the rotten ones then they rot
      //their neighbour and time 1 and then so on
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxtime=max(maxtime,time);
            
            for(int i=0;i<4;i++){
                int r=row+delrow[i];
                int c=col+delcol[i];
                if(r>=0 and r<n and c>=0 and c<m and vis[r][c]==0 and grid[r][c]==1){
                    q.push({{r,c},time+1});
                    vis[r][c]=2;
                    cnt++;
                }
            }
        }
        
        if(cnt!=freshcnt){
            return -1;
        }
        
        return maxtime;
        
        
    }
};
