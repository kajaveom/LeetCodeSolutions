class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> minRight(n, 0);
        minRight[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
//         for(auto m : minRight)
//             cout<<m<<" ";
//         cout<<endl;
        
        int minLeft = nums[0], res = 0;
        
        for(int i = 1; i < n-1; i++){
            if(nums[i] > minLeft && nums[i] < minRight[i+1])
                res += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1])
                res += 1;
            
            minLeft = max(minLeft, nums[i]);
        }
        
        return res;
    }
};