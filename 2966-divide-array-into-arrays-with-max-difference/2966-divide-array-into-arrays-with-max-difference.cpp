class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        int n = nums.size()/3, indx = 0;
        
        while(indx < nums.size()){
            if(nums[indx+2] - nums[indx] > k)
                return vector<vector<int>>{};
            
            res.push_back(vector<int>{nums[indx], nums[indx+1], nums[indx+2]});
            
            indx += 3;
        }
        
        return res;
        
    }
};