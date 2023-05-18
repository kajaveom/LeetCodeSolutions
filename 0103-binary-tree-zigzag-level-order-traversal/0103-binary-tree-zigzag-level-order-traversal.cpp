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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL)
            return vector<vector<int>>{};
        
        int dir = 1, activeStk = 1, ansIndex = 0;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        stk1.push(root);
        
        while(!stk1.empty() || !stk2.empty()){
            TreeNode* top;
            if(activeStk==1){
                top = stk1.top();
                stk1.pop();
            }
            else{
                top = stk2.top();
                stk2.pop();
            }
            
            ans[ansIndex].push_back(top->val);
            
            if(activeStk==1){
                if(dir==1){
                    if(top->left!=NULL)
                    stk2.push(top->left);
                    if(top->right!=NULL)
                    stk2.push(top->right);
                }
                else{
                    if(top->right!=NULL)
                    stk2.push(top->right);
                    if(top->left!=NULL)
                    stk2.push(top->left);
                }
            }
            else{
                if(dir==1){
                    if(top->left!=NULL)
                    stk1.push(top->left);
                    if(top->right!=NULL)
                    stk1.push(top->right);
                }
                else{
                    if(top->right!=NULL)
                    stk1.push(top->right);
                    if(top->left!=NULL)
                    stk1.push(top->left);
                }
            }
            
            if(activeStk==1 && stk1.empty()){
                activeStk = 2;
                ans.push_back(vector<int>{});
                ansIndex++;
                dir = 0;
            }
            else if(activeStk==2 && stk2.empty()){
                activeStk = 1;
                ans.push_back(vector<int>{});
                ansIndex++;
                dir = 1;
            }
        }
        
        ans.pop_back();
        
        return ans;
        
        
    }
};