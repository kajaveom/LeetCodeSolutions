class Solution {
public:
    
    vector<string> res;
    unordered_set<string> allPos;
    
    int getTotalInvalidP(string s){
        
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if(stk.empty() && !isalpha(s[i])){
                stk.push(s[i]);
            }
            else if(s[i]=='(')
                stk.push('(');
            else if(s[i]==')' && stk.top()=='(')
                stk.pop();
            else if(isalpha(s[i]))
                continue;
            else
                stk.push(s[i]);
        }
        
        return stk.size();
        
    }
    
    void generateAllPossible(string s, int del){
        
        if(allPos.find(s)!=allPos.end())
            return;
        else
            allPos.insert(s);
        
        if(del == 0){
            if(!getTotalInvalidP(s))
                res.push_back(s);
            return;
        }
        
        for(int i = 0; i < s.length(); i++){
            
            if(isalpha(s[i]))
                continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            generateAllPossible(left+right, del-1);
        }
        return;
        
    }
    
    
    
    
    vector<string> removeInvalidParentheses(string s) {
        
        int totInvalid = getTotalInvalidP(s);
        
        //cout<<totInvalid<<endl;
        generateAllPossible(s,totInvalid);      
        
        return res;
    }
    
};