class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto x : times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        for(int i = 0; i < n-1; i++){
            for(int j = 1; j < n+1; j++){
                if(adj[j].size()!=0){
                    for(auto e : adj[j]){
                        if( time[j] != INT_MAX && time[e.first] > time[j] + e.second)
                            time[e.first] = time[j] + e.second;
                    }
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(time[i]==INT_MAX)
                return -1;
            maxi = max(maxi, time[i]);
        }
        
        if(maxi==0)
            return -1;
        return maxi;
        
    }
};