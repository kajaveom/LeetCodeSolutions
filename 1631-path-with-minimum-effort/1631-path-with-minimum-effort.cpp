class Solution {
public:
    
    bool isSafe(int i, int j, int n, int m){
        if(i >= n || j >= m)
            return false;
        
        if(i < 0 || j < 0)
            return false;
        
        return true;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
    
        int n = heights.size(), m = heights[0].size();
        
        vector<vector<int>> adj[n][m];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(isSafe(i-1,j,n,m))
                    adj[i][j].push_back(vector<int>{i-1,j,abs(heights[i][j] - heights[i-1][j])});
                if(isSafe(i,j+1,n,m))
                    adj[i][j].push_back(vector<int>{i,j+1,abs(heights[i][j] - heights[i][j+1])});
                if(isSafe(i+1,j,n,m))
                    adj[i][j].push_back(vector<int>{i+1,j,abs(heights[i][j] - heights[i+1][j])});
                if(isSafe(i,j-1,n,m))
                    adj[i][j].push_back(vector<int>{i,j-1,abs(heights[i][j]- heights[i][j-1])});
                                                
                
            }
        }
        
        vector<vector<int>> fin(n, vector<int>(m,0));
        vector<vector<int>> cost(n, vector<int>(m,INT_MIN));
        
        fin[0][0] = 1;
        
        priority_queue< 
                    vector<int>,
                    vector<vector<int>>,
                    greater<vector<int>> > pq;
                            
        pq.push(vector<int>{INT_MIN,0,0});
        
        while(!pq.empty()){
            
            int i = pq.top()[1];
            int j = pq.top()[2];
            int h = pq.top()[0];
            
            pq.pop();
            
            fin[i][j] = 1;
            
            if(i==n-1 && j==m-1){
                if(cost[i][j]==INT_MIN)
                    return 0;
                return cost[i][j];
            }
                
            
            for(auto e : adj[i][j]){
                int v_i = e[0];
                int v_j = e[1];
                int h_uv = e[2];
                
                if(!fin[v_i][v_j]){
                    if(cost[v_i][v_j]==INT_MIN || cost[v_i][v_j] > max(h, h_uv))
                    {
                        cost[v_i][v_j] = max(h,h_uv);
                        //cout<<v_i<<" "<<v_j<<" "<<cost[v_i][v_j]<<" parent -> "<<i<<" "<<j<<endl;
                        pq.push(vector<int>{cost[v_i][v_j], v_i, v_j});
                    }
                }
            }
        }
                                        
        return 1;
                                        
        
        
        
        
        
        
        
    }
};