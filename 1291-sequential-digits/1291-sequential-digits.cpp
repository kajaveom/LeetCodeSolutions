class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> res;

        for (int i = 1; i <= 9; ++i) {
            
            int num = i;
            int next = num + 1;

            while (num <= high && next <= 9) {
                
                num = num * 10 + next;
                
                if (low <= num && num <= high) 
                    res.push_back(num);
                
                next++;
            }
        }

        sort(res.begin(), res.end());
        
        return res;
        
        
    }
};