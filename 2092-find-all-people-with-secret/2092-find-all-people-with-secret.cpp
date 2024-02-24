class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
     
        vector<int> ans;
        vector<pair<int,int>> adj[n+1];
        
        for(auto m : meetings){
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }
        
        vector<int> visited(n+1, 0);
        visited[0] = 1;
        
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        
        pq.push(vector<int>{0, firstPerson});
        for(auto v : adj[0]){
            pq.push({v.second, v.first});
        }
        
        ans.push_back(0);
        
        while(!pq.empty()){
            
            int time = pq.top()[0];
            int u = pq.top()[1];
            int tell_time = pq.top()[2];
            
            pq.pop();
            
            if(!visited[u])
                ans.push_back(u);
            visited[u] = 1;
            
            for(auto e : adj[u]){
                
                int v = e.first;
                int at_time = e.second;
                
                if(!visited[v] && at_time >= time)
                    pq.push(vector<int>{at_time, v});
                
            }
            
        }
        
        return ans;
        
        
    }
};