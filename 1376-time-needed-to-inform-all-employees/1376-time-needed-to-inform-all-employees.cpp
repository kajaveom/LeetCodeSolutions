class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
        vector<int> vis(n,0);
        vector<int> timeReq(n,0);
        
        queue<int> q;
        q.push(headID);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int wt = informTime[u];
            vis[u] = 1;
            
            for(auto v : adj[u]){
                if(!vis[v]){
                    timeReq[v] = timeReq[u] + wt;
                    q.push(v);
                }
            }
        }
        
        return *max_element(timeReq.begin(), timeReq.end());
        
        
        
        
        
    }
};