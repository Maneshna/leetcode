class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        int minSecondIndex = n;
        char ans = ' ';

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j < minSecondIndex) {
                        minSecondIndex = j;
                        ans = s[i];
                    }
                    break; // stop after first repeat for this character
                }
            }
        }

        return ans;
    }
};