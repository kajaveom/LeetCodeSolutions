class Solution {
public:
    
    int t[51][51][51][51];
    int getMax(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,int n)
    {
        if (i1>n-1 || i2>n-1 || j1>n-1 || j2>n-1 || grid[i1][j1]==-1 ||grid[i2][j2]==-1)
          return INT_MIN;
        
        if (i1==n-1 && j1==n-1 || i2==n-1 && j2==n-1 )
          return grid[i1][j1];
        
        if (t[i1][j1][i2][j2]!=-1)
          return t[i1][j1][i2][j2];
        
        
        int cherries=0;
        if (i1==i2 && j1==j2)
          cherries = grid[i1][j1];
        else
          cherries = grid[i1][j1]+grid[i2][j2];
        
        
        int temp=max({   getMax(i1+1,j1,i2+1,j2,grid,n),
                        
                        getMax(i1+1,j1,i2,j2+1,grid,n),
                      
                        getMax(i1,j1+1,i2,j2+1,grid,n),
                      
                      getMax(i1,j1+1,i2+1,j2,grid,n)     });
        
        
        return t[i1][j1][i2][j2]=cherries+temp;
          
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(t,-1,sizeof(t));
        return max(0,getMax(0,0,0,0,grid,n));
    }
};