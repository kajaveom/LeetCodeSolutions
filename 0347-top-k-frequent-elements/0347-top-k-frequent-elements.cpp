
#define pii pair<int,int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = 1;
            }
            else
                mp[nums[i]] += 1;
        }
        
        
        for(auto m : mp){
            if(pq.size() < k){
                pq.push({m.second, m.first});
            }
            else{
                if(m.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({m.second, m.first});
                }
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};