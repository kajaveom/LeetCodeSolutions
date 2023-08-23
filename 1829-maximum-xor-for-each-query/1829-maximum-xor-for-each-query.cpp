class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int xorSum = 0, n= nums.size(), j = n-1;
        for(int i = 0 ; i < n; i++)
            xorSum ^= nums[i];
        
        int ans = pow(2,maximumBit) - 1;
        vector<int> res;
        
        for(int i = 1; i<= n; i++){

            res.push_back(ans ^ xorSum);
            xorSum ^= nums[j];
            j--;
        }
        
       
        return res;
        
        
        
    }
};