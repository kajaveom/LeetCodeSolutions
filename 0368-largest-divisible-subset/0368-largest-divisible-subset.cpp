class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n,0);
        vector<int> hash(n,0);
        for(int i = 0;  i< n; i++)
            dp[i] = 1;
        
        int maxi = 1, lastIndex = 0;
        
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j] > dp[i]){
                    dp[i] = 1 +dp[j];
                    hash[i] = j;
                }
            }
            
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> res;
        while(lastIndex!=hash[lastIndex]){
            res.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        res.push_back(nums[lastIndex]);
        return res;
        
    }
};