class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n : nums){
            pq.push(n*n);
        }
        
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};