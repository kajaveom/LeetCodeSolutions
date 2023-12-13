class Solution {
public:
    
    bool isSafe(int i, int j, int m, int n){
        if(i < 0 || j <0 || i >= m || j >=n)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int tot_fresh = 0;
        queue<vector<int>> rots;
        
        
        int m = grid.size() , n = grid[0].size();
        int minTime = INT_MAX;
        
        vector<vector<int>> vis(m, vector<int>(n,0));
            
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j]==2){
                    rots.push(vector<int>{i,j,0});
                    vis[i][j] = 1;
                }
                    
                if(grid[i][j]==1)
                    tot_fresh++;
            }
        }
        
        if(tot_fresh==0)
            return 0;
        
     //   cout<<tot_fresh<<endl;
        
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!rots.empty()){
            int i = rots.front()[0];
            int j = rots.front()[1];
            int t = rots.front()[2];
            
            //cout<<i<<" "<<j<<" "<<t<<endl;
            
            rots.pop();
            
            vis[i][j] = 1;
            
            for(auto d : dir){
                int ni = i+d[0];
                int nj = j+d[1];
                
                if(isSafe(ni,nj,m,n) && grid[ni][nj]!=0 && !vis[ni][nj]){
                    rots.push(vector<int>{ni,nj,t+1});
                    vis[ni][nj] = 1;
                    tot_fresh--;
                    
                    if(tot_fresh==0)
                        return t+1;
                }
            }
        }
        
        return -1; 
        
    }
};