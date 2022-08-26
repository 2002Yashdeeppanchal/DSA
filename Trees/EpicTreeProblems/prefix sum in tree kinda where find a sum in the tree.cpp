https://leetcode.com/problems/path-sum-iii/submissions/



in this we do prefix sum in the tree while calculating we find the certain subtree whose sum up to targetSum 
how?
go to copy notes are there



void helper(TreeNode* root,int target,long long sum,int &cnt,unordered_map<long long int ,long long int> &m){
        
        if(root==nullptr){
            return;
        }
        
        sum+=root->val;
        
        if(m.find(sum-target)!=m.end()){
            cnt+=m[sum-target];
        }
        
        m[sum]++;
        
        helper(root->left,target,sum,cnt,m);
        helper(root->right,target,sum,cnt,m);
        
        m[sum]--;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long long int,long long int>m;
        m[0]++;
        
        int cnt=0;
        long long int sum=0;
        
        helper(root,targetSum,sum,cnt,m);
        
        return cnt;
        
    }
