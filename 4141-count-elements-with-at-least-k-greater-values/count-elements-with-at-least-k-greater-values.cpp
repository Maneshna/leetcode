class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // unique values sorted descending
        vector<int> values;
        for (auto &p : freq) {
            values.push_back(p.first);
        }
        sort(values.begin(), values.end(), greater<int>());

        int greaterCount = 0;
        int answer = 0;

        for (int val : values) {
            if (greaterCount >= k) {
                answer += freq[val];
            }
            greaterCount += freq[val];
        }

        return answer;
    }
};