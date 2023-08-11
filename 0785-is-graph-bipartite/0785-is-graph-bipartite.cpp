class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            int u = i;
            for(auto v : graph[i]){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        vector<int> color(n,-1);
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(color[i]!=-1)
                continue;
            
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v : adj[u]){
                    if(color[v]==-1){
                        color[v] = !color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u])
                        return false;
                }
            }
            
        }
        
        
        
        return true;
        
    }
};