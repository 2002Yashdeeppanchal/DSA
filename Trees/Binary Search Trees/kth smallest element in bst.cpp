


idea is simple that we do morris inorder traversal because in inorder of the bst gives the sorted list of all then nodes because left is smaller than the right
so when we go left we add smallest element and then root and larger ones so it gives a sorted list when we store them in a vector
but in this case we simply do cnt++ when we hit cnt==k then this node is the kth smaller one so this is our ans








int inorderTraversal(TreeNode* root,int k) {
        int cnt=0;
        int ans=-1;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==nullptr){//if curr->left is null then this is root so take it and move to right
                // inorder.push_back(curr->val);
                cnt++;
                cout<<cnt<<endl;
                if(cnt==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right!=nullptr and temp->right!=curr){//temp is curr's left and move mark the thread from temp's right most node to curr and this second condition is that if the thread is already exits then we compelte the circle to curr again that is we not wanted
                    temp=temp->right;
                }
                if(temp->right==nullptr){//if the thread is not exits then make it
                    temp->right=curr;
                    curr=curr->left;
                }
                else{//if exits then remove it 
                    temp->right=nullptr;
                    // inorder.push_back(curr->val);
                    cnt++;
                    cout<<cnt<<endl;
                    if(cnt==k)ans=curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=inorderTraversal(root,k);
        // cout<<ans->val;
        return ans;
    }
