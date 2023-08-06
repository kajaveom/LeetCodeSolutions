class Solution {
public:
    
    int search(vector<int> &nums, int q, int i, int j){
        
        if(i==j){
            if(q >= nums[i])
                return i+1;
            return i;
        }
        
        int mid = (i+j)/2;
        
        if(nums[mid]==q)
            return mid+1;
        
        if(q < nums[mid]){
            return search(nums,q,i,mid);
        }
        
        return search(nums,q,mid+1,j);
        
    }
    
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        vector<long long> pSum(n, 0);
        pSum[0] = nums[0];
        for(int i =1; i < n; i++){
            pSum[i] = pSum[i-1] + nums[i];
        }
        
        for(auto q : queries){
            long long pos = search(nums,q,0,n-1);
            long long leftReq = 0, rightReq = 0;
            if(pos==0){
                rightReq = pSum[n-1] - (n*q);
            }
            else if(pos==n){
                leftReq = (n*q) - pSum[n-1];
            }
            else{
                leftReq = (pos*q) - pSum[pos-1];
                rightReq = (pSum[n-1] - pSum[pos-1]) - (n-pos)*q;
            }
            
            ans.push_back(leftReq+rightReq);
        }
        
        return ans;
        
        
    }
};