class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int sm = 0, ssm = 0 , ele = 0;
        for(auto a : nums)
        {
            if(a <= target)
                sm++;
            if(a<target)
                ssm++;
            if(a==target)
                ele++;
        }
        
        if(ele==0)
            return vector<int>{};
        
        vector<int> res;
        for(int i = ssm; i <= sm-1; i++)
            res.push_back(i);
            
        return res;
    }
    
};