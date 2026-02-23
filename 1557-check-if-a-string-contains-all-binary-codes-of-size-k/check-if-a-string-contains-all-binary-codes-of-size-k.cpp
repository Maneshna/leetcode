class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int needed = 1 << k;  // 2^k using bit shift
        
        // Early return if string is too short
        if (s.length() < needed + k - 1) {
            return false;
        }
        
        // Use unordered_set to store unique substrings
        unordered_set<string> seen;
        
        // Extract all substrings of length k
        for (int i = 0; i <= s.length() - k; i++) {
            seen.insert(s.substr(i, k));
            
            // Optimization: early return if we found all codes
            if (seen.size() == needed) {
                return true;
            }
        }
        
        return seen.size() == needed;
        

        
    }
};