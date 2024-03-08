class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int max_f = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            max_f = max(max_f, mp[nums[i]]);
        }
        
        int res= 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == max_f)
                res++;
        }
        
        return res;
        
        
        
    }
};