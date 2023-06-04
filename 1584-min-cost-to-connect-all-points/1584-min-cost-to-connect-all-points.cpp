class Solution {
public:
    
    int getDist(vector<int> a, vector<int> b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0;
        
        int vCount = 1,curr = 0;
        visited[curr] = true;
        
        while(vCount < n){
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    int dis = getDist(points[curr], points[i]);
                  //  cout<<curr<<" "<<dis<<endl;
                    pq.push({dis, i});
                }
            }
            
            while(visited[pq.top().second])
                pq.pop();
            
            pair<int,int> close = pq.top();
            pq.pop();
            ans += close.first;
      //      cout<<curr<<" "<<close.first<<" "<<close.second<<endl;
            visited[close.second] = true;
            vCount++;
            curr = close.second;
        }
        
        return ans;
        
        
    }
};