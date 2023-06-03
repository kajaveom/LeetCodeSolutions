class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> visited(numCourses, false);
        vector<int> inDegree(numCourses, 0);
        vector<int> adj[numCourses];
        int count = 0;
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for(auto int i = 0; i < numCourses; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int v = q.front();
            ans.push_back(v);
            count++;
            q.pop();
            visited[v] = true;
            for(auto e : adj[v]){
                inDegree[e]--;
                if(inDegree[e] <= 0){
                    q.push(e);
                }
            }
        }
        if(count!=numCourses)
            return vector<int>{};
        return ans;
        
    }
};