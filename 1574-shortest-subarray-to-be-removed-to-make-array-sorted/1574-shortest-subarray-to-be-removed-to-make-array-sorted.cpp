class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n = arr.size();
        int left = 0, right = n-1;
        int i = 0, res = n-1;
        
        while(left < n-1 && arr[left] <= arr[left+1])
            left++;
        
        if(left==n-1)
            return 0;
        
        while(right > 0 && arr[right] >= arr[right-1])
            right--;
        
        res = min(n-left-1, right);
        
        while(i <= left && right < n)
        {
            if(arr[i] <= arr[right]){
                res = min(res, right-i-1);
                i++;
            }
            else{
                right++;
            }
        }        
        
        return res;
        
        
        
    }
};