class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int maxCust = 0, res = INT_MIN, n = grumpy.size();
        for(int i = 0; i < n; i++){
            maxCust += !grumpy[i]?customers[i]:0;
        }
        int i = 0, j = 0;
        
        while(j < n){
            if(grumpy[j])
                maxCust += customers[j];
            if(j-i+1 < minutes){
                j++;
            }
            else if(j-i+1==minutes){
                res = max(res, maxCust);
                if(grumpy[i])
                    maxCust-=customers[i];
                i++;
                j++;
            }
        }
        
        return res;
    }
    
};