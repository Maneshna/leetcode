class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Store the elements and their frequencies in a vector of pairs
        std::vector<std::pair<int, int>> freq_pairs;
        for (auto const& [num, count] : counts) {
            freq_pairs.push_back({num, count});
        }

        // Step 3: Sort the vector of pairs based on frequency in descending order
        // Custom comparator for sorting in descending order of the second element (frequency)
        std::sort(freq_pairs.begin(), freq_pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; 
        });

        // Step 4: Extract the top K elements
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freq_pairs[i].first);
        }

        return result;
    }
};