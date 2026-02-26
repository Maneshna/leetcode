class Solution {
public:
    int numSteps(string s) {
        int count = 0;
    int carry = 0;
    
    // process from right to left, skip the first bit (index 0)
    for (int i = s.size() - 1; i > 0; i--) {
        int bit = (s[i] - '0') + carry;
        
        if (bit % 2 == 1) {  
            carry = 1;
            count += 2;  
        } else {             
            count += 1;  
        }
    }
    
    
    if (carry) count++;
    
    return count;
    }
};