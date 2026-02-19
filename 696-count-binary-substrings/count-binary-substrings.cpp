class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
    int count = 1;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            count++;  // Same as previous, increase count
        } else {
            groups.push_back(count);  // Different, save count and reset
            count = 1;
        }
    }
    groups.push_back(count);  // Don't forget the last group
    
    // Step 2: Count valid substrings between adjacent groups
    int result = 0;
    for (int i = 1; i < groups.size(); i++) {
        result += min(groups[i-1], groups[i]);
    }
    
    return result;


        
    }
    
    
    
};