class Solution {
public:
    
//     int robMaximum(vector<int> &nums,int i, vector<int> &dp){
        
//         if(i >= nums.size())
//             return 0;
        
//         if(dp[i]!=-1)
//             return dp[i];
        
//         int w1 = nums[i] + robMaximum(nums,i+2,dp);
//         int w2 = robMaximum(nums,i+1,dp);
        
//         return dp[i] = max(w1,w2);
//     }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        //vector<int> dp(n+2,-1);
        
        int next2 = 0, next1 = 0, cur;
        for(int i = n-1; i >= 0; i--){
            int w1 = nums[i] + next2;
            int w2 = next1;

            cur = max(w1,w2);
            next2 = next1;
            next1 = cur;
        }
        
        return cur;
        
    }
};