class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    //phle to sb kuch apni jgh pr krna hai na to input matrix ko hi change krna pdega
	    //to sbse phle to jo -1 hai unko inf krde(unki shortest dist nikalni hai abhi)
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
	    //ab bs har i->j ko via jane ki try kro
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][via] + matrix[via][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][via] + matrix[via][j];
	                }
	            }
	        }
	    }
	    
	    //if there is negative cycle then reaching to node itself is not 0 it is negative
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<n;j++){
	   //         if(matrix[i][j] < 0){
	                
	   //         }
	   //     }
	   // }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    
	}
};
