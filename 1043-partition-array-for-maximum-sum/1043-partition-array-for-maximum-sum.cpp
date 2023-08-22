class Solution {
public:
    
    int getMaxSum(vector<int> &arr, int i, int k, vector<int> &dp){
        
        if(i >= arr.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int max_sum = 0, maxi = arr[i];
        for(int j = i; j < i+k; j++){
            
            if(j >= arr.size())
                break;
            maxi = max(maxi, arr[j]);
            max_sum = max(max_sum , (j-i+1)*maxi + getMaxSum(arr,j+1,k, dp));
        }
        
        return dp[i] = max_sum;
        
    }
    
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n,-1);
        
        return getMaxSum(arr, 0, k, dp);
    }
};