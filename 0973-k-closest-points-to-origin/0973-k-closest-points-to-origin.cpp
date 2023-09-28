class Solution {
public:
    
    double distOrigin(int x, int y){
        return sqrt(x*x + y*y);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<double>> pq;
        
        for(auto p : points){
            
            // if(!pq.empty())
            // cout<<pq.top()[1]<<" "<<pq.top()[2]<<endl;
            
            if(pq.size() < k)
                pq.push(vector<double>{distOrigin(p[0], p[1]) , (double)p[0], (double)p[1]});
            else{
                //cout<<pq.top()[0]<<" "<<distOrigin(p[0], p[1])<<endl;
                if(pq.top()[0] > distOrigin(p[0], p[1])){
                    pq.pop();
                    pq.push(vector<double>{distOrigin(p[0],p[1]) , (double)p[0], (double)p[1]});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(vector<int>{(int)pq.top()[1] , (int)pq.top()[2]});
            pq.pop();
        }
        
        return ans;
        
    }
};