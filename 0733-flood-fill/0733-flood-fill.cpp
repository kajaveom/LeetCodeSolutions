class Solution {
public:
    
//     bool isSafe(int i, int j, int n, int m){
        
//     }
    int v[51][51];
    void dfs(vector<vector<int>> &adj, int i, int j, int n, int m, int c, int sp){
        
        
        
        if(i < 0 || j < 0 || i>=n || j >= m)
            return;

        if(adj[i][j] != sp)
            return;
        
        if(v[i][j])
            return;
        //cout<<i<<" "<<j<<endl;
        
        adj[i][j] = c;
        v[i][j] = 1;
        dfs(adj,i+1,j,n,m,c, sp);
        dfs(adj,i,j+1,n,m,c, sp);
        dfs(adj,i-1,j,n,m,c, sp);
        dfs(adj,i,j-1,n,m,c,sp);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size(), m = image[0].size();
        memset(v,0,sizeof(v));
        dfs(image,sr,sc,n,m,color, image[sr][sc]);
        
        return image;
        
    }
};