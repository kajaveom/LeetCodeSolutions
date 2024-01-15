class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int maxi = 0, len = 0;
        for(int i = citations.size() -1 ; i >= 0; i--){
            
            if(citations[i] >= len+1){
                maxi = max(maxi, len+1);
                len++;
            }
            else{
                break;
            }
        }
        
        return maxi;
        
        
    }
};