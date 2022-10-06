vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==nullptr){//if curr->left is null then this is root so take it and move to right
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right!=nullptr and temp->right!=curr){//temp is curr's left and move mark the thread  from temp's right most node to curr and this second condition is that if the thread is already exits then we compelte the circle to curr again that is we not wanted
                    temp=temp->right;
                }
                if(temp->right==nullptr){//if the thread is not exits then make it
                    temp->right=curr;
                    curr=curr->left;
                }
                else{//if exits then remove it 
                    temp->right=nullptr;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
