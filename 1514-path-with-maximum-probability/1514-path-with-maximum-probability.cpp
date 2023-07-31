class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<int> fin(n,0);
        vector<double> maxProb(n,INT_MIN);
        
        vector<vector<double>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            double prob = succProb[i];
            adj[n1].push_back(vector<double>{(double)n2,prob});
            adj[n2].push_back(vector<double>{(double)n1,prob});
        }
        
        // for(int i = 0; i < n; i++){
        //     cout<<i<<endl;
        //     for(auto v : adj[i]){
        //         cout<<v[0]<<" "<<v[1]<<endl;
        //     }
        //     cout<<endl<<endl;
        // }
        
        fin[start_node] = 1;
        maxProb[start_node] = 1;
        
        priority_queue<vector<double>> pq;
        
        pq.push(vector<double>{1.0,(double)start_node});
        
        while(!pq.empty()){
            int u = pq.top()[1];
            double w = pq.top()[0];
            pq.pop();
            
           // cout<<u<<" "<<w<<endl;
            
            fin[u] = 1;
            if(u == end_node)
                return maxProb[u];
            
            for(auto e : adj[u]){
                int v = e[0];
                double p_uv = e[1];
                if(!fin[v]){
                    if(maxProb[v] < w * p_uv){
                        maxProb[v] = w * p_uv;
                        pq.push(vector<double>{maxProb[v], (double)v});
                    }
                }
            }
        }
        
        return 0;
        
        
        
    }
};