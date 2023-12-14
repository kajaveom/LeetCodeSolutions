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
    
    void dfs(vector<int> adj[], vector<int> &res, int u, int k, vector<int> &vis, int dist){
        
        vis[u] = true;
        if(dist==k)
            res.push_back(u);
        
        for(auto v : adj[u]){
            
            if(!vis[v]){
                dfs(adj, res, v, k, vis, dist+1);
            }
            
        }
        
        return;
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> adj[501];
        vector<int> vis(501,0);
        vector<int> res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode* fnt = q.front();
            q.pop();
            if(fnt->left == NULL && fnt->right==NULL)
                continue;
            
            if(fnt->left!=NULL){
                adj[fnt->val].push_back((fnt->left)->val);
                adj[(fnt->left)->val].push_back(fnt->val);
                
                q.push(fnt->left);
            }
            
            if(fnt->right!=NULL){
                adj[fnt->val].push_back((fnt->right)->val);
                adj[(fnt->right)->val].push_back(fnt->val);
                
                q.push(fnt->right);
            }
        }
        
        
        dfs(adj, res, target->val, k, vis, 0);
        
        return res;
        
        
    }
};