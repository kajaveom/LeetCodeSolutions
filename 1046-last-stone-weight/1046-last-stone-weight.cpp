class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s : stones){
            pq.push(s);
        }
        
        while(pq.size()>1){
            
            //cout<<"yes"<<endl;
            
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        
        // if(pq.empty())
        //     return 0;
        
        return pq.top();
    }
};