brute method is to create a list (inorder jo hona chahiye) by morris and sort it

then create inorder jo hai iska 

do array me traverse kro jo do nodes ki val alg hai unko swap kro

like 

1 2 3 4
1 3 2 4

this take O(n) spaces




optimallly can be done in copy

class Solution {
    
    private : 
    TreeNode* first;
    TreeNode* mid;
    TreeNode* prev;
    TreeNode* last;
    
    private :
    
    void inorder(TreeNode *node){
        if(node==NULL)return;
        
        inorder(node->left);
        
        if(prev!=nullptr and (node->val < prev->val)){//violation
            if(first==nullptr){
                first=prev;
                mid=node;
            }
            else{
                last=node;
            }
        }
        
        prev=node;
        
        inorder(node->right);
    }

    
    
    
public:
    
    void recoverTree(TreeNode* root) {
        first=last=mid=nullptr;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first!=nullptr and last!=nullptr){
            //when 2 violation
            swap(first->val,last->val);
        }
        else{
            swap(first->val,mid->val);
        }
    }
};
