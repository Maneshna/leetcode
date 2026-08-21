class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for(const string& word : words){
            freqMap[word]++;
        }

        auto comp = [](const pair<string, int>& a, const pair<string, int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp) > minHeap(comp);

        for(const auto& entry : freqMap){
            minHeap.push(entry);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<string> result(k);
        for(int i = k-1; i>=0; --i){
            result[i] = minHeap.top().first;
            minHeap.pop();
        }
        return result;
        
    }
};