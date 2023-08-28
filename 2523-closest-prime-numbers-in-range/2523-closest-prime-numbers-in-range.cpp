class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        
        vector<int> pNum(right+1 , 1);
        for(int i = 2; i*i <= right; i++){
            
            if(pNum[i]==0)
                continue;
            
            for(int j = i+i; j <= right; j+=i)
                pNum[j] = 0;
        }
        pNum[1] = 0;
        
        int res = INT_MAX, prevPrime = -1, nextNum = -1, curPrime;
        for(int i = left; i <= right; i++){
            if(pNum[i]){
                if(prevPrime==-1)
                {    
                    prevPrime = i;
                    curPrime = i;
                }
                else
                {
                    if(res > i - curPrime){
                        res = i-curPrime;
                        prevPrime = curPrime;
                        nextNum = i; 
                    }
                    
                    if(res == 1)
                        return vector<int>{prevPrime, nextNum};
                }
                curPrime = i; 
            }
        }
        
        // return pNum;
        
        if(nextNum==-1)
            return vector<int>{-1,-1};
        
        return vector<int>{prevPrime, nextNum};

        
    }
};