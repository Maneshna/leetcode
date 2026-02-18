class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = "";
        while (n > 0) {
        if (n % 2 == 0) {
            binary = "0" + binary;
        } else {
            binary = "1" + binary;
        }
        n = n / 2;
    }
    
    // Step 2: Check if adjacent bits are different
    for (int i = 1; i < binary.length(); i++) {
        if (binary[i] == binary[i-1]) {
            return false;  // Found two same adjacent bits
        }
    }
    
    return true;
        
        
    }
};