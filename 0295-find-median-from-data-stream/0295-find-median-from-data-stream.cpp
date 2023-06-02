class MedianFinder {
public:
    
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2; 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size()==0){
            pq1.push(num);
            return;
        }
        
        if(pq1.size() > pq2.size()){
            
            int maxLeft = pq1.top();
            if(num > maxLeft){
                pq2.push(num);
            }
            else{
                pq2.push(maxLeft);
                pq1.pop();
                pq1.push(num);
            }
            
            return;
            
        }
        
        if(pq1.size() == pq2.size()){
            int maxLeft = pq2.top();
            if(num <= maxLeft){
                pq1.push(num);
            }
            else{
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            
            return;
        }
        
        
        
    }
    
    double findMedian() {
        
        int n = pq1.size() + pq2.size();
        if(n % 2 == 0){
            double ans = (double)(pq1.top() + pq2.top()) / 2;
            return ans;
        }
        
        return pq1.top();
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */