class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(auto x : nums)
            st.insert(x);
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]-1) == st.end()){
                int cur = 1;
                while(st.find(nums[i]+cur) != st.end()){
                    cur++;
                }
                res = max(res,cur);
            }
        }
        return res;
    }
};