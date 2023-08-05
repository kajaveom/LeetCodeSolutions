class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string numS = to_string(num);
        int i = 0, res = 0;
        
        for(int i = 0; i < numS.length()-k+1; i++)
        {
            string t = numS.substr(i,k);
            int div = stoi(t);
            if(div!=0 && num % div==0)
                res++;
        }
        return res;
    }
};