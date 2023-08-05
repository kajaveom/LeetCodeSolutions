class Solution {
public:
    
    int countWays(vector<int> &nums, int i, int sum, int t, vector<vector<int>> &dp, int th){
        
        if(i>= nums.size() && sum==t)
            return 1;
        
        if(i >= nums.size())
            return 0;
        
        if(dp[i][sum+th]!=-1)
            return dp[i][sum+th];
        
        return dp[i][sum+th] = countWays(nums, i+1, sum+nums[i], t, dp, th) + 
                                    countWays(nums, i+1, sum-nums[i], t, dp, th);
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
    
        int posSum = 0;
        for(auto a : nums){
            if(a>0)
                posSum += a;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(posSum + posSum + 1, -1));
        
        int thresh = posSum;
        
        return countWays(nums,0,0,target, dp, thresh);
    }
};