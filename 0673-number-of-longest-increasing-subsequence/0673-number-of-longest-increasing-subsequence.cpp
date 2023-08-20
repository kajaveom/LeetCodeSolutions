class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int res = 0, maxi = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        
        // for(auto a : dp)
        //     cout<<a<<" ";
        // cout<<endl;
        // for(auto a : cnt)
        //     cout<<a<<" ";
        // cout<<endl;
        
        maxi = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < n; i++){
            if(dp[i]==maxi)
                res+=cnt[i];
        }
        
        return res;
        
    }
};