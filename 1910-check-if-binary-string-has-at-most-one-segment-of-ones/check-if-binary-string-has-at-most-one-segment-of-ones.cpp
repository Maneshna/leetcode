class Solution {
public:
    bool checkOnesSegment(string s) {
        bool segmentEnded = false;
        for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(segmentEnded) return false;
        } 
        else { // s[i] == '0'
            if(i > 0 && s[i-1] == '1')
                segmentEnded = true;
        }
    }

    return true;

        
    }
};