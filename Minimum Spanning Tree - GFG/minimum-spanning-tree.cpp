//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void findMinSpanTree(int v, vector<vector<int>> adj[], int cost){
	    
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cost = 0;
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minheap;
        vector<int> mSet(V,0);
        vector<int> key(V,INT_MAX);
        
        
        minheap.push(vector<int>{0,0}); /// weight - vertex - parent
        key[0] = 0;
        
        int count = V;
        
        while(!minheap.empty()){
    
            vector<int> tp = minheap.top();
            minheap.pop();
            int w = tp[0];
            int u = tp[1];
            
            if(mSet[u]==1)
            continue;
            
            mSet[u] = 1;
            cost += w;
            
            for(auto v : adj[u]){
                if(!mSet[v[0]]){
                    minheap.push(vector<int>{ v[1] ,v[0]});
                } 
            }
            
            //cout<<minheap.size()<<endl;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends