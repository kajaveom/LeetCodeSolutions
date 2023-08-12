class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int min=  0;
        int max = 0;
        int taps = 0;
        int lastIndex = 0;
        
        int s = ranges.size();
        
        while(max < n){
            
            for(int i = lastIndex; i < s ; i++){
                if(i-ranges[i] <= min && i+ranges[i]>max)
                {
                    max = i + ranges[i];
                    lastIndex = i;
                }
            }
            if(max==min)
                return -1;
            taps++;
            min = max;
        }
        
        return taps;
        
    }
};