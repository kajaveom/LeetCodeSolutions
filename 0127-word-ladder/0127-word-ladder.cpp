class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        
        unordered_set<string> vis;
        unordered_set<string> st;
        for(auto str : wordList)
            st.insert(str);
        
        while(!q.empty()){
            string f = q.front().first;
            int c = q.front().second;
            q.pop();
            vis.insert(f);
            
            if(f==endWord)
                return c;
            
            //childs
            for(int i = 0; i < f.length(); i++){
                char tmp = f[i];
                for(int j = 0; j < 26; j++){
                    f[i] = 'a' + j;
                    if(vis.find(f)==vis.end() && st.find(f)!=st.end()){
                        q.push(make_pair(f,c+1));
                    }
                }
                f[i] = tmp;
            }
        }
        
        return 0;
        
        
        
        
    }
};