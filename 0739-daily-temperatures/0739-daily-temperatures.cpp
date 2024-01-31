class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
     
        int n = t.size();
        int i = n-2;
        vector<int> ans(n,0);
        
        stack<int> stk;
        ans[n-1] = 0;
        
        stk.push(n-1);
        while(i >= 0){
            
            while(!stk.empty() && t[stk.top()] <= t[i])
            {
                stk.pop();
            }
            
            ans[i] = stk.empty()?0:(stk.top() - i);
            stk.push(i);
            i--;
        }
        return ans;  
    }
};