class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequencies
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // 2. Maintain a min-heap of size k
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for (auto& [element, freq] : count) {
            min_heap.push({freq, element});
            if (min_heap.size() > k) {
                min_heap.pop(); 
            }
        }
        
        // 3. Extract results from heap
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};