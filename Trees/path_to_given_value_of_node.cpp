we do check left and right and storing in a ds





bool helper(TreeNode* A,int B,vector<int> &ans){
    if(A==NULL){
        return false;
    }
    ans.push_back(A->val);
    if(A->val==B){
        return true;
    }
    bool left=helper(A->left,B,ans);
    if(left==true){
        return true;
    }
    bool right=helper(A->right,B,ans);
    if(right==true){
        return true;
    }    
    if(left==false and right==false){
        ans.erase(ans.begin()+ans.size()-1);
        return false;
    }
    
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    helper(A,B,ans);
    return ans;
}

