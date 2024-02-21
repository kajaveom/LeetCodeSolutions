class Solution {
    
public:
    
    int highestPowerof2(unsigned int n)
    {
  
        if (n < 1)
            return 0;
        int res = 1;
   
        for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
            int curr = 1 << i;
 
            if (curr > n)
                break;
            res = curr;
        }
        return res;
    }

    
    
    int rangeBitwiseAnd(long long left, long long right) {
        
        
        long long highleft= highestPowerof2(left);
        long long highright = highestPowerof2(right);
        
        if(highleft != highright)
            return 0;
        
        long long res = left;
        for(long long j = left+1; j <= right; j++){

            res = res & j;
            
        }
            
        return res;
    }
};