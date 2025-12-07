class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int n = s.size();
        int best = 0;
        int left = 0; // window is [left, right]

        for (int right = 0; right < n; ++right) {
            unsigned char c = s[right];
            // If c was seen inside current window, move left right after
            // its last index to ensure uniqueness.
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            // Update last seen index for c
            last[c] = right;

            // Window size = right - left + 1
            best = max(best, right - left + 1);
        }
        return best;
    }
};