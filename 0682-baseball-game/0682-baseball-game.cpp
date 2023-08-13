class Solution {
public:
    int calPoints(vector<string>& op) {
        
        vector<int> ans;
        int res = 0, n = 0;
        
        for(auto c : op){
            if(c=="+"){
                ans.push_back(ans[n-1] + ans[n-2]);
                n++;
            }
            else if(c == "C"){
                ans.pop_back();
                n--;
            }
            else if(c == "D"){
                ans.push_back(ans[n-1]*2);
                n++;
            }
            else{
                ans.push_back(stoi(c));
                n++;
            }
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
        
        
    }
};