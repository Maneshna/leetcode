class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
         int m = str1.size();
        int n = str2.size();

        // Step 1: Build LCS DP table
        vector<vector<int>> dp(
            m + 1, vector<int>(n + 1, 0)
        );

        for(int i = 1; i <= m; i++) {

            for(int j = 1; j <= n; j++) {

                if(str1[i-1] == str2[j-1]) {

                    dp[i][j] = 1 + dp[i-1][j-1];

                }
                else {

                    dp[i][j] = max(
                        dp[i-1][j],
                        dp[i][j-1]
                    );
                }
            }
        }

        // Step 2: Reconstruct the SCS
        string ans = "";

        int i = m;
        int j = n;

        while(i > 0 && j > 0) {

            // Characters match
            if(str1[i-1] == str2[j-1]) {

                ans += str1[i-1];

                i--;
                j--;
            }

            // Take character from str1
            else if(dp[i-1][j] > dp[i][j-1]) {

                ans += str1[i-1];
                i--;
            }

            // Take character from str2
            else {

                ans += str2[j-1];
                j--;
            }
        }

        // Step 3: Add remaining characters
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }

        while(j > 0) {
            ans += str2[j-1];
            j--;
        }

        // Step 4: Reverse the answer
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};