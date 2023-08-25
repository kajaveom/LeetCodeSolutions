class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int cost = 0, i = startPos[0], j = startPos[1];
        
        while(i!=homePos[0]){
            if(i < homePos[0])
                i++;
            else
                i--;
            cost += rowCosts[i];
        }
        
        while(j!=homePos[1]){
            if(j < homePos[1])
                j++;
            else
                j--;
            cost += colCosts[j];
        }
        
        return cost;
    }
};