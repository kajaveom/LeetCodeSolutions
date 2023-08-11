//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int visited[501][501];

    void dfs(vector<vector<char>> &grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        
        if(i < 0 || j < 0 || i >= n || j >= m)
        return;
    
        if(visited[i][j])
        return;
        
        if(grid[i][j]=='0')
        return;
        
        visited[i][j] = 1;
        
        dfs(grid, i+1,j);
        dfs(grid,i+1,j-1);
        dfs(grid,i+1,j+1);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i-1,j-1);
        dfs(grid,i-1,j+1);
        
        return;
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        memset(visited, 0, sizeof(visited));
        
        int res = 0;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j]=='0')
                continue;
                
                if(visited[i][j])
                continue;
                
                res++;
                dfs(grid,i,j);
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends