//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    
    void tarjans(vector<int> adj[], int u, vector<int>& disc, vector<int>& low, 
                    int &time, stack<int>& stk, vector<bool>& inStack, 
                        vector<vector<int>>& ans){
                            
                            
        time++;
        disc[u] = low[u] = time;
        stk.push(u);
        inStack[u] = true;
        
        for(auto v : adj[u]){
            if(disc[v]==-1){
                tarjans(adj,v,disc,low,time,stk,inStack,ans);
                
                low[u] = min(low[u], low[v]);
            }
            
            else if(inStack[v] == true){
                low[u] = min(low[u], disc[v]);
            }
        }
        
        int n = ans.size();
        if(low[u] == disc[u]){
            ans.push_back(vector<int>{});
            while(stk.top()!=u){
               ans[n].push_back(stk.top());
               inStack[stk.top()] = false;
               stk.pop();
            }
            ans[n].push_back(stk.top());
            inStack[stk.top()] = false;
            stk.pop();
        }
                            
    }
    
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> low(V);
        vector<int> disc(V,-1);
        int time = 0;
        stack<int> stk;
        vector<bool> inStack(V, false);
        for(int u = 0; u < V; u++){
            if(disc[u]==-1){
                tarjans(adj, u, disc, low, time, stk, inStack, ans);
            }
        }
        
        for(auto &vec : ans){
            sort(vec.begin(), vec.end());
        }
        sort(ans.begin(), ans.end());
        
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends