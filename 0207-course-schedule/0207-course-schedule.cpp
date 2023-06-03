class Solution {
public:
    
    bool dfs(vector<int> adj[], int i, vector<bool>& visited, vector<bool> currVisited){
        
        //cout<<i<<endl;
        visited[i] = true;
        currVisited[i] = true;
        for(auto e : adj[i]){
            if(!visited[e] && dfs(adj,e, visited, currVisited))
                return true;
            if(currVisited[e])
                return true;
        }
        currVisited[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto v : prerequisites)
            adj[v[0]].push_back(v[1]);
        
        vector<bool> visited(numCourses, false);
        vector<bool> currVisited(numCourses, false);
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(adj, i, visited, currVisited))
                    return false;
            }
        }
        return true;
    }
};