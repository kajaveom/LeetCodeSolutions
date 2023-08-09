class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxJump = 0;
        for(int i = 0; i <nums.size(); i++){
            if(nums[i] > maxJump){
                maxJump = nums[i];
            }
            maxJump--;
            
          //  cout<<i<<" "<<maxJump<<endl;
            
            if(i == nums.size()-1)
                return true;      
            
            if(maxJump < 0)
                return false;
        }
        
        return true;
        
        
    }
};