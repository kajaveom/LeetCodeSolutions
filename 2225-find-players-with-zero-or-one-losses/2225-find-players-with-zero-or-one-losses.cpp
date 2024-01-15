class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> oneLoss;
        vector<int> noLoss;

        map<int,int> loss;
        for(auto x : matches){
            if(loss.find(x[1]) == loss.end()){
                loss[x[1]] = 1;
            }
            else
            loss[x[1]]++;

            if(loss.find(x[0]) == loss.end()){
                loss[x[0]] = 0;
            }
        }

        for(auto x : loss){
            if(x.second == 0)
            noLoss.push_back(x.first);
            if(x.second == 1)
            oneLoss.push_back(x.first);
        }

        return vector<vector<int>>{noLoss,oneLoss};
    }
};