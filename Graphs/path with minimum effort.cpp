class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        pq.push({0,{0,0}});
        
        int delrow[]={0,-1,+1,0};
        int delcol[]={-1,0,0,+1};
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int maxdiff_in_this_path=it.first;//in this path this is the max effort taken
            int row=it.second.first;
            int col=it.second.second;
            
            if(row==n-1 and col==m-1){
                return maxdiff_in_this_path;
            }
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    int neweffort=max(maxdiff_in_this_path,abs(heights[nrow][ncol]-heights[row][col]));
                    if(dist[nrow][ncol] > neweffort){
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
            
        }
        
    }
};
