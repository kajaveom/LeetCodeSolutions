class Solution {
public:
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum==0 || finalSum%2!=0)
            return vector<long long>{};
        
        vector<long long> res;
        
        long long sum = 0, num = 2;
        while(1){
            
            if(sum+num < finalSum){
                sum += num;
                res.push_back(num);
                num += 2;
            }
            else{
                if(sum + num == finalSum){
                    res.push_back(num);
                    return res;
                }
                    
                
                int diff = finalSum - sum;
                res[res.size()-1] += diff;
                break;
            }
            
        }
        
        return res;
        
        
        
        
        
    }
};