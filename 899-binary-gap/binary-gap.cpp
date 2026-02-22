class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        int lastOne = -1;  // position of last seen '1'
        int pos = 0;
        
        while(n > 0) {
            if(n & 1) {  // current bit is 1
                if(lastOne != -1) {
                    maxDist = max(maxDist, pos - lastOne);
                }
                lastOne = pos;
            }
            n >>= 1;  // shift right
            pos++;
        }
        
        return maxDist;
        
    }
};