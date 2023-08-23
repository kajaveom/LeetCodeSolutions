class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        priority_queue<vector<int>> maxH;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > minH;
        
        int i = 0, j = 0, n = nums.size();
        long long res = 0;
        
        while(j < n){
           /// cout<<j<<endl;
            maxH.push(vector<int>{nums[j],j});
            minH.push(vector<int>{nums[j],j});
            
            while(!maxH.empty() && maxH.top()[1]<i)
                maxH.pop();
                
            while(!minH.empty() && minH.top()[1]<i)
                minH.pop();
            
           // cout<<maxH.top()[0]<<" "<<minH.top()[0]<<endl;
            
            if(abs ( maxH.top()[0] - minH.top()[0] ) <= 2){
                res += (j-i+1);
                j++;
            }
            else{
                i++;  
            }
        }
        
        return res;
        
        
    }
};