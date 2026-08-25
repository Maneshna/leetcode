class Solution {
public:

    bool isPalindrome(const string& s, int left, int right){
        while(left<right){
            if(s[left] != s[right]){
                return false;
                
            }
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n =s.length();
        if(n<=1) return s;

        int maxLen = 0;
        int start = 0;

        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                if(isPalindrome(s,i,j)){
                    int currentLen = j-i+1;
                    if(currentLen > maxLen){
                        maxLen = currentLen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
        
    }
};