class Solution {
public:
    int expandAroundCenter(const string& s, int left, int right){
        while(left >=0 && right<s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start =0;
        int maxLen = 0;

        for(int i =0;i<s.length(); i++){
            int Len1 = expandAroundCenter(s, i, i);
            int Len2 = expandAroundCenter(s, i, i+1);
            int currentMax = max(Len1, Len2);

            if(currentMax > maxLen){
                maxLen = currentMax;
                start = i-(currentMax-1) /2;
            }
        }
        return s.substr(start, maxLen);
         
        
    }
};