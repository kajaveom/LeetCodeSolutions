class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int st = 0, ed = tokens.size()-1;
        int ret = 0;
        int cur = 0;
        while(ed >= st){
            if(P >= tokens[st]){
                P -= tokens[st];
                cur++;
                st++;
            }
            else if (cur > 0){
                P += tokens[ed];
                cur --;
                ed--;
            }
            else 
                return ret;
            if(cur > ret) 
                ret = cur;
        }
        return ret;
    }
};