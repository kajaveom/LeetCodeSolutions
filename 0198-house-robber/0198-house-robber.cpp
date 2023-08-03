class Solution {
public:
    
    int robMaximum(vector<int> &nums,int i, vector<int> &dp){
        
        if(i >= nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int w1 = nums[i] + robMaximum(nums,i+2,dp);
        int w2 = robMaximum(nums,i+1,dp);
        
        return dp[i] = max(w1,w2);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);
        return robMaximum(nums,0,dp);
        
    }
};