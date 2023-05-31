/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans = 0;
    
    int getKth(TreeNode* root, int k, int& cnt){
        if(root== NULL)
            return 0;
        
        if(cnt >= k)
            return 0;
        
        getKth(root->left, k, cnt);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return 0;
        }
        getKth(root->right,k, cnt);
        
        return 0;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        getKth(root,k,cnt);
        return ans;
    }
};