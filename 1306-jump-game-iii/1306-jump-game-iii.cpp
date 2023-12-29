class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            
            int fnt = q.front();
            q.pop();
            vis[fnt] = 1;
            if(arr[fnt]==0)
                return true;
            
            if(arr[fnt]+fnt < n && !vis[arr[fnt]+fnt])
                q.push(arr[fnt]+fnt);
            if(fnt - arr[fnt]>= 0 && !vis[fnt-arr[fnt]])
                q.push(fnt-arr[fnt]);
        }
        
        
        return false;
        
        
    }
};