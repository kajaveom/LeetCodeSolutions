class Solution {
public:
    
    int getIndex(char c){
        return (c -'0') - 49;
    }    
    
    int getMaxLen(vector<string> &arr, int i , int bitMap){
        
        if(i >= arr.size())
            return 0;
        
        
        //case not take
        int case1 = getMaxLen(arr, i+1, bitMap);
        
        //case take
        int case2 = 0, flag = false, charBitMap = (1 << 27);
        for(auto c : arr[i]){
            int indx = getIndex(c);
            int setIndx = (1 << indx);
            if((bitMap & (setIndx)) || (charBitMap & (setIndx))){
                flag = true;
                  break;
            }
            else{
                charBitMap |= setIndx;
            }
        }
        
        if(!flag){
            for(auto c : arr[i]){
                bitMap |= (1 << getIndex(c));
            }
            
            case2 = getMaxLen(arr,i+1,bitMap) + arr[i].length();
        }
        
        
        return max(case1, case2);   
    }
    
    
    int maxLength(vector<string>& arr) {
        
        int bitMap = (1 << 27);
        return getMaxLen(arr, 0, bitMap);
        
        
    }
};