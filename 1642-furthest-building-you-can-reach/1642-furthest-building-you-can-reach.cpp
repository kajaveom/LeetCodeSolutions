class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> pq;
        int i = 0;
        for(i = 1; i < heights.size(); i++){
            int diff = heights[i] - heights[i-1];
            
            if(diff > 0){
                
                bricks -= diff;
                pq.push(diff);
                
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                
                if(ladders < 0)
                    return i-1;
            }
            
        }
        
        return i-1;
        
        
    }
};