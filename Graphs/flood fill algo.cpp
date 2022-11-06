class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>> &image,vector<vector<int>> &ans,int inicolor,int newcolor,int delrow[],int delcol[]){
        //first color krdo
        ans[sr][sc]=newcolor;
        int n=image.size();
        int m=image[0].size();
        //neighbours me dekho
        for(int i=0;i<4;i++){
            int r=sr+delrow[i];
            int c=sc+delcol[i];
            if(r>=0 and r<n and c>=0 and c<m and image[r][c]==inicolor and ans[r][c]!=newcolor){
                dfs(r,c,image,ans,inicolor,newcolor,delrow,delcol);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
    int newcolor) {
        
        int n=image.size();
        int m=image[0].size();
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={0,-1,0,1};
        int delcol[]={1,0,-1,0};
        dfs(sr,sc,image,ans,inicolor,newcolor,delrow,delcol);
        
        return ans;
        
    }
};
