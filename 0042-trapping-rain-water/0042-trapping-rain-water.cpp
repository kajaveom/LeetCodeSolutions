class Solution {
public:
    
    
    void findLeftGreater(vector<int> h, vector<int> &lG){
        
        int n = h.size();
        lG[0] = -1;
        stack<int> stk;
        stk.push(h[0]);
        
        for(int i = 1; i < n; i++){
            while(!stk.empty() && stk.top()<=h[i]){
                stk.pop();
            }
            lG[i] = stk.empty()?-1:stk.top();
            if(stk.empty() || h[i] > stk.top())
            stk.push(h[i]);
        }

        return;
    }
    
    
    void findRightGreater(vector<int> h, vector<int> &rG){
        
        int n = h.size();
        rG[n-1] = -1;
        stack<int> stk;
        stk.push(h[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            while(!stk.empty() && stk.top()<=h[i]){
                stk.pop();
            }
            rG[i] = stk.empty()?-1:stk.top();
            if(stk.empty() || h[i] > stk.top())
            stk.push(h[i]);
        }
        return;
    }
    
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> lG(n,0);
        vector<int> rG(n,0);
        
        findLeftGreater(height,lG);
        findRightGreater(height,rG);
        
        
        int res = 0;
        for(int i = 1; i < n-1; i++){
           // cout<<lG[i]<<" "<<rG[i]<<" "<<height[i]<<endl;
            if(lG[i]!=-1 && rG[i]!=-1){
                
                res += min(lG[i], rG[i]) - height[i];
            }
                
        }
        
        return res;
        
        
        
        
        
    }
};