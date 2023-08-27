class Solution {
public:
    int minimumBuckets(string ham) {
        
        if(ham.length()==1){
            if(ham[0]=='.')
                return 0;
            if(ham[0]=='H')
                return -1;
        }
        
        
        int res  = 0;
        for(int i = 0; i < ham.length(); i++){

            if(ham[i]=='H'){
                if(i==0){
                    if(ham[i+1]=='H')
                        return -1;
                    else {
                        ham[i+1] = '#';
                          res++;
                    }
                }
                else if(i==ham.length()-1)
                {
                    if(ham[i-1]=='H')
                    {
                        return -1;
                    }
                    else if(ham[i-1]=='.')
                    {
                        res++;
                    }
                }else{
                    if(ham[i+1]=='H'){
                        if(ham[i-1]=='H')
                            return -1;
                        else if(ham[i-1]=='.')
                            res++;
                    }
                    else if(ham[i-1]=='#'){
                        continue;
                    }
                    else if(ham[i+1]=='.'){
                        res++;
                        ham[i+1]='#';
                    }
                }
            }
        }
        
        return res;
    }
};