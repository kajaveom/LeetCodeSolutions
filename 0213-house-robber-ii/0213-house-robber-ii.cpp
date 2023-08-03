class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n==2)
            return max(nums[0], nums[1]);
        
        //vector<int> dp(n+2,-1);
        
        int next2 = 0, next1 = 0, cur;
        for(int i = n-2; i >= 0; i--){
            int w1 = nums[i] + next2;
            int w2 = next1;

            cur = max(w1,w2);
            next2 = next1;
            next1 = cur;
        }
        
        int max1 = cur;
        next2 = 0, next1 = 0;
        
        for(int i = n-1; i > 0; i--){
            int w1 = nums[i] + next2;
            int w2 = next1;

            cur = max(w1,w2);
            next2 = next1;
            next1 = cur;
        }
        
        
        return max(max1,cur);
        
        
    }
};