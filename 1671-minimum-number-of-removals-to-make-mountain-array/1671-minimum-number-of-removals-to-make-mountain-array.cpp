class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j]<nums[i] && lis[j]+1 > lis[i]){
                    lis[i] = 1+lis[j];
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(nums[j]<nums[i] && lds[j]+1 > lds[i]){
                    lds[i] = 1 + lds[j];
                }
            }
        }
        
        int res = 0;
        
//         for(auto l : lis)
//             cout<<l<<" ";
//         cout<<endl;
//         for(auto l : lds)
//             cout<<l<<" ";
        
        for(int i = 1; i < n-1; i++){
            if(lis[i]>1 && lds[i]>1)
            res = max(res, lis[i] + lds[i] -1);
        }
        
        return n-res;
        
        
    }
};