class Solution {
public:
    
    static bool myCmp(const vector<int>& a, const vector<int>& b){
        
        double f1 = (double)(a[1]*a[0])/a[0];
        double f2 = (double)(b[1]*b[0])/b[0];
        
        return f1 > f2;
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), myCmp);
        
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); i++){
            if(boxTypes[i][0] > truckSize)
            {
                ans += truckSize * boxTypes[i][1];
                break;
            }
            else{
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][0] * boxTypes[i][1];
            }   
            
        }
        
        return ans;
        
    }
};