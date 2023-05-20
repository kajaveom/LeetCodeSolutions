class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        int n = security.size();
        vector<int> lS(n, 0);
        vector<int> rS(n, 0);
        lS[0] = 1;
        for(int i = 1; i < n; i++){
           if(security[i] <= security[i-1]){
               lS[i] = lS[i-1] + 1;
           }
            else{
                lS[i] = 1;
            }
        }
        rS[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(security[i] <= security[i+1]){
               rS[i] = rS[i+1] + 1;
           }
            else{
                rS[i] = 1;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(lS[i]-1 >= time && rS[i]-1>= time)
                ans.push_back(i);
        }
        return ans;
        
    }
};