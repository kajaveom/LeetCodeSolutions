class Solution {
public:
    
    void dfs(vector<pair<int,int>> adj[], vector<int> &val, int &res,int u,int curVal, int curTime, int maxTime)     {
        
        if(curTime > maxTime)
            return;
        
        curVal += val[u];
        
        if(u==0)
            res = max(res, curVal);
        
        int temp = val[u];
        val[u] = 0;
        for(auto v: adj[u]){
            dfs(adj, val, res, v.first, curVal, curTime+v.second, maxTime);
        }
        val[u] = temp;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        
        int n = values.size();
        vector<pair<int,int>> adj[n];
        
        for(auto e : edges){
            adj[e[0]].push_back(make_pair(e[1],e[2]));
            adj[e[1]].push_back(make_pair(e[0],e[2]));
        }
        
        
        int res = INT_MIN;
        
        dfs(adj, values, res, 0,0 ,0, maxTime);
        
        
        return res;
    }
};