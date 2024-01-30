class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        
        stack<string> stk;
        int x1, x2, res;

        for(int i=0; i<tokens.size(); ++i)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                stk.push(tokens[i]);

            else
            {
                x1 = stoi(stk.top()); stk.pop();
                x2 = stoi(stk.top()); stk.pop();

                if(tokens[i] == "+")
                    res = x2 + x1;

                else if(tokens[i] == "-")
                    res = x2 - x1;

                else if(tokens[i] == "*")
                    res = x2 * x1;

                else
                    res = x2 / x1;

                stk.push(to_string(res));
            }
        }

        return stoi(stk.top());
        
        
        
        
    }
};