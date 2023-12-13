class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int diff = INT_MAX, res = -1;
        
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                    return sum;
                
                if(diff > abs(sum-target)){
                    diff = abs(sum-target);
                    res = sum;
                }
                
                if(sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        
        return res;
        
        
    }
};