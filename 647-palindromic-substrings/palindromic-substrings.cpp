class Solution {
public:
    int countSubstrings(string s) {
        int count =0;
        int n = s.length();
        for(int i =0;i<n; i++){
            count += expandaroundCenter(s,i,i);
            count += expandaroundCenter(s, i,i+1);
        }
        return count;
        
    }

private:
    int expandaroundCenter(const string& s, int left, int right){
        int palindrome =0;
        while(left>=0 && right <s.length()&& s[left]==s[right]){
            palindrome++;
            left--;
            right++;
        }
        return palindrome;
    }
};