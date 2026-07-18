class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int>lastseen(128, -1);

        int maxlength = 0;
        int left =0;

        for(int right = 0; right<s.length(); ++right){
            char currentChar = s[right];

            if(lastseen[currentChar] >= left){
                left = lastseen[currentChar] +1;



            }
            lastseen[currentChar] = right;
            maxlength = max(maxlength, right-left+1);
        }
        return maxlength;
        
    }
};