class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> actual_count;
        
        for(auto c : t)
            actual_count[c]++;
        
        unordered_map<char,int> expected_count;
        int tot_count = 0;
        
        int i = 0, j = 0, n = s.length(), start = -1, end = -1, len = INT_MAX;
        
        while(j < n){
            
            if(actual_count.find(s[j]) == actual_count.end()){
                j++;
            }
            else{
                
                if(expected_count.find(s[j])==expected_count.end() || expected_count[s[j]] < actual_count[s[j]]){
                    expected_count[s[j]]++;
                    tot_count++;
                }
                else{
                    expected_count[s[j]]++;
                }
                
                if(tot_count == t.length()){
                    
                   // cout<<i<<" "<<j<<endl;
                    
                    while(i < j){
                        if(expected_count.find(s[i]) == expected_count.end())
                        {
                            i++;
                        }
                        else if(expected_count[s[i]] > actual_count[s[i]]){
                            expected_count[s[i]]--;
                            i++;
                        }
                        else{
                            break;
                        }
                    }  
                    
                   // cout<<i<<" "<<j<<endl;
                    
                    if(j-i+1 < len){
                        len = j-i+1;
                        start = i;
                        end = j;
                    }
                    
                    expected_count[s[i]]--;
                    i++;
                    tot_count--;
                   
                }
                j++;
            }
            
        }
        
        if(start == -1 && end == -1)
            return "";
        
        return s.substr(start,end-start+1);
        
        
        
        
        
    }
};