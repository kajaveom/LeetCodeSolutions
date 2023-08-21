class Solution {
public:
    
    int dp[303][303];

    
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, 0, sizeof(dp));
        
        int n = nums.size();
    
        for(int i = n-2; i >= 1; i--){
            for(int j = i; j <= n-2; j++){
                int maxi = INT_MIN;
                for(int k = i; k <= j; k++){
                    maxi = max(maxi, nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] +                                                                               dp[k+1][j]);
                }

                dp[i][j] = maxi;
            }
        }
        
        
        return dp[1][n-2];
        
        
    }
};