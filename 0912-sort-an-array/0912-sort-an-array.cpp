class Solution {
public:
    
    vector<int> merge(vector<int> &left, vector<int> &right){
        vector<int> res;
        int i = 0, j = 0, n = size(left), m = size(right);

        while(i < n and j < m){
            if(left[i] < right[j]) 
                res.push_back(left[i++]);
            else 
                res.push_back(right[j++]);
        }

        while(i < n) 
            res.push_back(left[i++]);
        while(j < m) 
            res.push_back(right[j++]);
        
        return res;
    }

    vector<int> mergeSort(int i, int j, vector<int> &nums){
        if(i == j) 
            return {nums[i]};
        
        int mid = i + (j - i) / 2;
        
        vector<int> left = mergeSort(i, mid, nums);
        vector<int> right = mergeSort(mid + 1, j, nums);
        
        return merge(left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = size(nums);
        return mergeSort(0, n - 1, nums);
    }
};