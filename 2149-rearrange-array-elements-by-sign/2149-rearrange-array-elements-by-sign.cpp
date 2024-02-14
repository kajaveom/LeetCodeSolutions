class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;

        for(int i =0; i < nums.size(); i++)
        {
            if(nums[i] <0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }

        int i = 0, j = 0;
        for(int k= 0; k < nums.size(); k++){
            if(k%2==0){
                ans.push_back(pos[i]); i++;
            }
            else{
                ans.push_back(neg[j]); j++;
            }
        }

        return ans;

        
        
    }
};