class Solution {
public:
    
    int dp[301][301];
    int getMaxCoins(vector<int> &nums, int i, int j){
        
        if(i > j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k = i; k <= j; k++){
            maxi = max(maxi, nums[i-1]*nums[k]*nums[j+1] + getMaxCoins(nums, i,k-1) + getMaxCoins(nums,k+1,j));
        }
        
        return dp[i][j] = maxi;
    }
    
    
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        
        int n = nums.size();
    
        
        return getMaxCoins(nums, 1, n-2);
        
        
    }
};