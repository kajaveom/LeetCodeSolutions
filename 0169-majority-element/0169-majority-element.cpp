class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        int c = 0, ans = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(c == 0)
                ans = nums[i];
            if(nums[i] == ans){
                c += 1;
            }
            else{
                c -= 1;
            }
        }
        
        
        return ans;
    }
};