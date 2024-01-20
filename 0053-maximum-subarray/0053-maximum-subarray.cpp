class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_till_now = INT_MIN, max_ending_here = 0;
        
        for(int i = 0; i < nums.size(); i++){
            max_ending_here += nums[i];
            
            if(max_ending_here > max_till_now){
                max_till_now = max_ending_here;
            }
            
            if(max_ending_here < 0){
                max_ending_here = 0;
            }
        }
        
        return max_till_now;
        
        
    }
};