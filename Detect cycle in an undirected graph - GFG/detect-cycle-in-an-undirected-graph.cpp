//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkCycleBfs(int v, vector<int> adj[]){
        
        vector<bool> visited(v, false);
        queue<pair<int,int>> q;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                q.push({i,-1});
                while(!q.empty()){
                    pair<int,int> f = q.front();
                    q.pop();
                    visited[f.first] = true;
                    for(auto e : adj[f.first]){
                        if(visited[e] && e!=f.second)
                            return true;
                        if(!visited[e]){
                            visited[e] = true;
                            q.push({e,f.first});
                        }
                    }
                }
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        // vector<vector<int>> adjMat(V, vector<int>(V,0));
        // for(int i = 0; i < V; i++){
        //     for(auto j : adj[i]){
        //         adjMat[i][j] = 1;
        //     }
        // }
        
        return checkCycleBfs(V,adj);
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends