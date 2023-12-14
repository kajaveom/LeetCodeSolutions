class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> stk;
        
        int o=0, c=0;
        int to=0, tc=0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='('){
                to++;
                stk.push(1);
                o++;
            }
            else if(s[i]==')'){
                tc++;
                if(stk.empty() || !stk.top()){
                    c++;
                }
                else{
                    stk.pop();
                    o--;
                }
            }
        }
        
        // cout<<o<<" "<<c<<endl;
        // cout<<to<<" "<<tc<<endl;
        
        int no = to-o,nc = tc-c;
        
        stack<int> stk2;
        string res = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='(' && no>0){
                res += '(';
                no--;
                stk2.push(1);
            }
            else if(s[i]==')'){
                if(!stk2.empty() && nc>0){
                    res += ')';
                    nc--;
                    stk2.pop();
                }  
            }
            else if(s[i]!='(' && s[i]!=')')
                res += s[i];
            
        }
        
        return res;
    }
};