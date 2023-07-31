//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> fin(V,0);
        vector<int> cost(V,INT_MAX);
        priority_queue<vector<int>,
                        vector<vector<int>>,
                            greater<vector<int>>> pq;
                        
        
        fin[S] = 1;
        cost[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            
            int u = pq.top()[1];
            int w = pq.top()[0];
            pq.pop();
            fin[u] = 1;
            
            for(auto e : adj[u]){
                int v = e[0];
                int uv_w = e[1];
                
                if(!fin[v]){
                    if(cost[v] > w + uv_w){
                        cost[v] = w + uv_w;
                        pq.push({cost[v] , v});
                    }
                }
            }
            
        }
        
        return cost;
        
        
        
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends