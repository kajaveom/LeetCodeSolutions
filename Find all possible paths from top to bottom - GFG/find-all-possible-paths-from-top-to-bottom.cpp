//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    void getAllPaths(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &res, vector<int> cur){
        
   //     cout<<i<<" "<<j<<endl;
        
        if(i==n-1 && j==m-1){
            cur.push_back(grid[i][j]);
            res.push_back(cur);
            return;
        }
        
        if(i >= n || j >= m)
        return;
        
        cur.push_back(grid[i][j]);
        getAllPaths(i+1,j,n,m,grid,res,cur);
        getAllPaths(i,j+1,n,m,grid,res,cur);
        
        return;   
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> res;
        getAllPaths(0,0,n,m,grid,res,vector<int>{});
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends