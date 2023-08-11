//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
   
    int vis[501][501];
    
    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m)
        return false;
        return true;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
    
        memset(vis,0,sizeof(vis));
        queue<vector<int>> q;
        int n = grid.size() , m = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==2)
                q.push(vector<int>{i,j,0});
            }
        }
        
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int res = 0;
        
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            
           // cout<<i<<" "<<j<<endl;
            
            vis[i][j] = 1;
            int t = q.front()[2];
            res = max(res, t);
            q.pop();
            
            for(auto d : dir){
                
                if(isSafe(i+d[0], j + d[1], n, m))
                {
                    //cout<<i+d[0]<<" "<<j+d[1]<<endl;
                    
                    if(grid[i+d[0]][j+d[1]]==0 || grid[i+d[0]][j+d[1]]==2)
                    continue;
                    
                    if(!vis[i+d[0]][j+d[1]]){
                        vis[i+d[0]][j+d[1]] = 1;
                        q.push(vector<int>{i+d[0], j + d[1], t+1});
                    }
                    
                }
                
                //cout<<endl<<endl;
            }
        }
        
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1 && !vis[i][j])
                return -1;
            }
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends