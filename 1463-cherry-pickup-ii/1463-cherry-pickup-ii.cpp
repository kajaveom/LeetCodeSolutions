class Solution {
public:
    
    int dp[70][70][70][70];
    
    int getMaximum(vector<vector<int>> &grid, int i1, int j1, int i2, int j2, int n, int m){
        
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -500;
        
        if(i1==n-1 && i2==n-1){
            if(j1!=j2)
                return grid[i1][j1] + grid[i2][j2];
            return grid[i1][j1];
        }
        
        if(i1==n-1)
        return grid[i1][j1];
        
        if(i2==n-1)
        return grid[i2][j2];
        
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        
        int cherries= 0;
        if(i1==i2 && j1==j2)
            cherries = grid[i1][j1];
        else
            cherries = grid[i1][j1] + grid[i2][j2];
        
        //case1 l-l
        int c1 = getMaximum(grid,i1+1,j1-1,i2+1,j2-1,n,m);
        //case2 l-m
        int c2 = getMaximum(grid,i1+1,j1-1,i2+1,j2,n,m);
        //case3 l-r
        int c3 = getMaximum(grid,i1+1,j1-1,i2+1,j2+1,n,m);
        
        //case4 m-l
        int c4 = getMaximum(grid,i1+1,j1,i2+1,j2-1,n,m);
        //case5 m-m
        int c5 = getMaximum(grid,i1+1,j1,i2+1,j2,n,m);
        //case6 m-r
        int c6 = getMaximum(grid,i1+1,j1,i2+1,j2+1,n,m);
        
        //case7 r-l
        int c7 = getMaximum(grid,i1+1,j1+1,i2+1,j2-1,n,m);
        //case8 r-m
        int c8 = getMaximum(grid,i1+1,j1+1,i2+1,j2,n,m);
        //case9 r-r
        int c9 = getMaximum(grid,i1+1,j1+1,i2+1,j2+1,n,m);
        
        return dp[i1][j1][i2][j2] = cherries + max({c1,c2,c3,c4,c5,c6,c7,c8,c9});
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        return getMaximum(grid, 0,0,0,m-1,n,m);
        
        //return 1;
        
        
    }
};