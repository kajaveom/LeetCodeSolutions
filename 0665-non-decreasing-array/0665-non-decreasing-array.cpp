class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int pos = -1, n = nums.size();
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(pos!=-1)
                    return false;
                pos = i;
            }
        }
        
        if(pos==-1 || 
            pos == 0 ||
            pos == n-2 ||
            nums[pos-1] <= nums[pos+1] ||
           nums[pos] <= nums[pos+2]
          )
            return true;
        
        return false;
        
    }
};