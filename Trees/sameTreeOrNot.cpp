//simple hai p ko jo kro q ko bhi kro same aate rhe to true ni to false read code sb smj jaega kafi easy hai
//ek or sol hai ki dono ka traversal same hoga to koi sa bhi traversal lgao same aana chiye


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }
        if(p==NULL and q!=NULL)return false;
        if(p!=NULL and q==NULL)return false;
        if(p->val!=q->val)return false;
        if(!isSameTree(p->left,q->left) or !isSameTree(p->right,q->right))return false;
        return true;
    }
