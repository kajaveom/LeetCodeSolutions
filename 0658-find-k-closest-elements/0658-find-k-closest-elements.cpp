class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int s = 0, e = 0;
        int i = 0, j = 0;
        int minSum = INT_MAX, sum = 0;
        
        while(j < arr.size()){
            sum += abs(arr[j]-x);
            if(j-i+1==k){
                if(sum < minSum){
                    s = i; e = j;
                    minSum = sum;
                }
                sum -= abs(arr[i]-x);
                i++; j++;
            }
            else if(j-i+1 < k){
                j++;
            }
        }
        
        vector<int> ans;
        for(int i = s; i <= e; i++){
            ans.push_back(arr[i]);
        }
        return ans;
        
    }
};