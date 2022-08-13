class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)return "";//if root is null
        
        queue<TreeNode*>q;
        q.push(root);
        string s;
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr)s.append("#,");
            else s.append(to_string(curr->val)+',');
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())return nullptr;
        stringstream sso(data);
        string str;
        getline(sso,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            getline(sso,str,',');
            if(str=="#"){
                curr->left=nullptr;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                curr->left=leftnode;
                q.push(leftnode);
            }
            getline(sso,str,',');
            if(str=="#"){
                curr->right=nullptr;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                curr->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
