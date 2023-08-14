//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool canColor(bool g[101][101], int u, int col, int n, vector<int> &colList){
        
        for(int k = 0; k < n; k++){
            if(k!=u && g[k][u]==1 && colList[k]==col)
            return false;
        }
        return true;
    }


    bool solve(bool graph[101][101], int u, vector<int> &colList, int m, int n){
        
        if(u == n)
        return true;
        
        for(int i = 1; i <= m; i++){
            if(canColor(graph,u,i,n,colList)){
                colList[u] = i;
                if(solve(graph,u+1,colList,m,n))
                return true;
                colList[u] = 0;
            }
        }
        
        return false;
    }

    

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> col(n,0);
        
        if(solve(graph, 0,col, m, n))
        return true;
        
        return false;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends