class Solution {
public:
    
    bool canPart(vector<int> &nums, int i, int t, vector<vector<int>> &dp){
        
        if(t < 0)
            return false;
        if(t == 0)
            return true;
        
        if(i >= nums.size())
        return false;
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        return dp[i][t] = canPart(nums,i+1,t-nums[i],dp) | canPart(nums, i+1, t, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto a : nums)
            sum += a;
        
        if(sum%2!=0)
            return false;
        
        int t = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(t+1,-1));
        return canPart(nums, 0, t, dp);
        
    }
};