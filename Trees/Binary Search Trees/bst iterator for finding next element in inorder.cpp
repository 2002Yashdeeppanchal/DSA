//idea is that we can store inorder by morris in a vector and do the job it is 
//tc of O(n) and O(n)space job 
// but in this sol we use stack when the call assemble we push all the left ones in the stack from the root to left most node then 
//if the call of next is made then we return st.top() but before returing push all the right node's left in the stack


class BSTIterator {
    private : 
        stack<TreeNode*>st;
    
public:
    
    void pushall(TreeNode* root){
        TreeNode* curr=root;
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        int ans=st.top()->val;
        TreeNode* temp=st.top();
        st.pop();
        pushall(temp->right);
        
        return ans;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
