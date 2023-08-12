class Solution {
public:
    
    int leftAns = 0, rightAns = 0, res = INT_MAX;
    
    void minVal(string s, int l, int r, int p){
        
        if(l < 0 || r >= s.length())
            return;
        
        int leftPart = 1, rightPart = 1;
        
        if(l > 0)
        leftPart = stoi(s.substr(0,l));
        if(r < s.length()-1)
        rightPart = stoi(s.substr(r+1));
        
        int midPart1 = stoi(s.substr(l,p-l));
        int midPart2 = stoi(s.substr(p+1, r-p));
        
        int ans = leftPart * (midPart1 + midPart2) * rightPart;
        
      //  cout<<leftPart<<" "<<midPart1<<" "<<midPart2<<" "<<rightPart<<endl;
       // cout<<l<<" "<<r<<" "<<ans<<endl;
        //cout<<endl;
        if(ans < res){
            res = ans;
            leftAns = l;
            rightAns = r;
        }
        
        minVal(s,l-1,r,p);
        minVal(s,l,r+1,p);
        
    }
    
    
    string minimizeResult(string expression) {
        int pIndx = 0;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i]=='+')
            {
                pIndx = i;
                break;
            }
        }
        
        minVal(expression,pIndx-1, pIndx+1,pIndx);
        
        string resStr = "";
        for(int i = 0; i < expression.length(); i++){
            if(i == leftAns){
                resStr += '('; 
                resStr += expression[i];  
            }
            else if(i == rightAns){
                resStr += expression[i];
                resStr += ')';
            }
            else{
                resStr += expression[i];
            }
        }
        
        return resStr;
    }
};