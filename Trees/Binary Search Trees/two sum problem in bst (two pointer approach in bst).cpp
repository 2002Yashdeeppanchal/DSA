beautiful problem

we done bstiterator problem in that problem we find next element in inorder by calling next function means from starting (smaller to greater)

we create reverse logic rightnodeleft in bstiterator problem to find the before element means from last(greater to smaller)
  


class BSTIteratorbefore {
    private : 
        stack<TreeNode*>st;
    
public:
    //in this we push all the right ones and then left's right ones then so on (simply inorder in reverse order)
    void pushall(TreeNode* root){
        TreeNode* curr=root;
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->right;
        }
    }
    
    BSTIteratorbefore(TreeNode* root) {
        pushall(root);
    }
    
    int before() {
        int ans=st.top()->val;
        TreeNode* temp=st.top();
        st.pop();
        pushall(temp->left);
        
        return ans;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};



class BSTIteratornext {
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
    
    BSTIteratornext(TreeNode* root) {
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



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIteratornext l(root);
        BSTIteratorbefore r(root);
          
        int i=l.next();//stands at smallest val node in bst (inorder's first node) if inorder is a vector
        int j=r.before();//stands at largest val node in bst(inorder's last node) if inorder is a vector
        //this is simple two pointer approach
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.before();
            }
        }
        return false;
    }
};
