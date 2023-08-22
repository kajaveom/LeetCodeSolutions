class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        
        
        vector<string> res;
        if(nums.size()==0)
            return res;
        string t = "";
        
        int s = 0, e = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1]+1== nums[i]){
                e++;
            }
            else{
                if(s==e){
                    res.push_back(to_string(nums[s]));
                }
                else{
                    t = to_string(nums[s]) + "->" + to_string(nums[e]);
                    res.push_back(t);
                }
                s = i;
                e = i;
            }
        }
        
        if(s==e){
            res.push_back(to_string(nums[s]));
        }
        else{
            t = to_string(nums[s]) + "->" + to_string(nums[e]);
            res.push_back(t);
        }
        
        
        
        return res;
        
    }
};