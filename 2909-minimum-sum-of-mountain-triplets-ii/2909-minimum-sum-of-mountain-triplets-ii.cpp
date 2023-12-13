class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> minRight(n,0);
        
        int minFromRight = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            minFromRight = min(minFromRight, nums[i]);
            minRight[i] = minFromRight;
        }
        
        int mini = nums[0], res = INT_MAX;
        
        for(int i = 1; i < n-1; i++){
            if(nums[i] > mini && nums[i] > minRight[i+1]){
                res = min(res, mini + nums[i] + minRight[i+1]);
            }
            
            mini = min(mini, nums[i]);
        }
        
        return res==INT_MAX?-1:res;
        
    }
};