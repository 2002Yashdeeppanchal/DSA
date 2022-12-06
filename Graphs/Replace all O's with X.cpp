class Solution{
    
private: 
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,
        int delrow[],int delcol[]){
            
        int n=mat.size();
        int m=mat[0].size();
        
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat,delrow,delcol);
            }
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={0,-1,+1,0};
        int delcol[]={-1,0,0,+1};
        //first check for the first row and last row
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 and mat[0][i]=='O'){
                vis[0][i]=1;
                dfs(0,i,vis,mat,delrow,delcol);
            }
            if(vis[n-1][i]==0 and mat[n-1][i]=='O'){
                vis[n-1][i]=1;
                dfs(n-1,i,vis,mat,delrow,delcol);
            }
        }
        
        //check for the first col and last col
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 and mat[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,vis,mat,delrow,delcol);
            }
            if(vis[i][m-1]==0 and mat[i][m-1]=='O'){
                vis[i][m-1]=1;
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        
        //check for the whole mat
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
        
    }
};
