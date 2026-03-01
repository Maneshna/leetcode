class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = *max_element(n.begin(), n.end());
        return maxDigit - '0';


        
    }
};