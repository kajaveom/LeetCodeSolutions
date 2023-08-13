class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int res = nums.size(), maxCnt = 0;
        unordered_map<int,int> fIndx;
        unordered_map<int,int> cnt;
        
        for(int i = 0; i < nums.size(); i++){
            if(fIndx.find(nums[i])==fIndx.end()){
                fIndx[nums[i]] = i;
                cnt[nums[i]] = 1;
                
                if(maxCnt < 1){
                    maxCnt = 1;
                    res = 1;
                }
            }
            else {
                cnt[nums[i]]++;
                if(cnt[nums[i]] > maxCnt){
                    res = i - fIndx[nums[i]] + 1;
                    maxCnt = cnt[nums[i]];
                }
                else if(cnt[nums[i]]==maxCnt)
                    res = min(res, i - fIndx[nums[i]] + 1);
            }
        }
        
        return res;
        
    }
};