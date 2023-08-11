//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	bool dfs(vector<int> adj[], int u, vector<int> &dis, vector<int> &low, 
	                                vector<int> &vis, int p, int t, int c, int d){
	    ++t;
	    dis[u] = t;
	    low[u] = t;
	    
	    vis[u] =1;
	    for(auto v : adj[u]){
	        if(!vis[v]){
	            bool res = dfs(adj,v,dis,low,vis,u,t,c,d);
	            if(res)
	            return res;
	            
	            low[u] = min(low[u], low[v]);
	            
	            if(low[v] > dis[u]){
	                if((u==c && v==d) || (u==d && v==c))
	                return true;
	            }
	        }
	        
	        else if(v != p)
	        low[u] = min(dis[v] , low[u]);
	    }
	    
	    
	    
	    return false;
	}
	
	bool solve(vector<int> adj[], int V, int u, int v){
	    
	    vector<int> dis(V,0);
	    vector<int> low(V,0);
	    vector<int> visited(V,0);
	    int t = 0;
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            if(dfs(adj,u,dis,low,visited,-1,t,u,v))
	            return true;
	        }
	    }
	    
	    return false;
	    
	}
	
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        return solve(adj,V,c,d);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends