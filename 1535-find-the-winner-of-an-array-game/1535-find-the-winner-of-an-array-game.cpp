class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(k >= arr.size()){
            return *max_element(arr.begin(), arr.end());
        }
        
        if(k == 1)
            return arr[0]>arr[1]?arr[0]:arr[1];
        
        int i = 0, j = 1, cnt = 0, cnt2 = 0;
        while(1){
            while(arr[i] > arr[j]){
                cnt++;
                if(cnt==k)
                    return arr[i];
                j++;
                
                if(j >= arr.size())
                return arr[i];
            }
            i++;
            j = i+1;
            cnt = 1;
            
            if(j >= arr.size())
                return arr[i];
        }
        return 1;
       
    }
};