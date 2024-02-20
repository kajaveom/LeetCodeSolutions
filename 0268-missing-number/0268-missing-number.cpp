class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxi = nums.size(), sum = 0;
        for(auto x: nums)
        sum+=x;
        int asum = (maxi*(maxi+1))/2;
        return asum - sum;
    }
};