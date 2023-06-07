class Solution {
public:
    
    void dfs(vector<int> adj[], int u,vector<bool>& visited, 
                vector<int>& disc, vector<int>& low, vector<vector<int>>& ans,
                    int &time, int p){
        
        visited[u] = true;
        time++;
        disc[u] = time;
        low[u] = time;
        
        for(auto v : adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited,disc,low,ans,time,u);
                
                low[u] = min(low[u], low[v]);
                
                if(low[v] > disc[u]){
                    ans.push_back(vector<int>{u,v});
                }
            }
            
            else if(v != p){
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
    vector<vector<int>> bridges(vector<int> adj[], int v){
        
        vector<bool> visited(v, false);
        vector<int> disc(v, 0);
        vector<int> low(v);
        vector<vector<int>> ans;
        int time = 0, parent = -1;
        
        for(int u = 0; u < v; u++){
            if(!visited[u])
                dfs(adj,u,visited, disc,low,ans,time,parent);
        }
        
        return ans;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        return bridges(adj, n);
        
        
        
    }
};