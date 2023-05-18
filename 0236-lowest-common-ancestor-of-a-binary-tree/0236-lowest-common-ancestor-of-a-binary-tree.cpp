/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* res;
    bool flag = false;
    
    int isPresent(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root==NULL)
            return 0;
        
        int s;
        
        if(root->val == p->val || root->val==q->val){
            s = 1 + isPresent(root->left, p, q) + isPresent(root->right, p ,q);
        }
        else{
            s = isPresent(root->left,p,q) + isPresent(root->right, p ,q);
        }
        
        //cout<<root->val<<" "<<s<<endl;
        if(!flag && s==2)
        {
            res = root;
            flag = true;
        }
        
        return s;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isPresent(root,p,q);
        return res;
    }
};