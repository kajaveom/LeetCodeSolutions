class Solution {
public:
    
    int conComp = 0;
    
    int dfs(vector<int> adj[], int u, vector<int> &vis, int p){
        
        vis[u] = 1;
        conComp++;
        int edges = 0;
        for(auto v : adj[u]){
            if(v > u)
                edges++;
            if(!vis[v]){
                edges += dfs(adj,v,vis,u);
            }
        }
        return edges;
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> visited(n,0);
        vector<int> adj[n];
        for(auto e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // for(auto i : adj){
        //     for(auto v : i){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int extra = 0, uncon = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                uncon++;
                int e  = 0;
                e = dfs(adj, i, visited, -1);
               // cout<<e<<endl;
                extra += e - (conComp-1);
                conComp = 0;
            }
        }
        
        if(uncon-1 <= extra)
            return uncon-1;

        
        return -1;
        
        
        
    }
};