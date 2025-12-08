class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size()*2);

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());         // O(k log k) where k = s.length()
            mp[key].push_back(move(s));           // move to avoid copy
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for (auto &p : mp) ans.push_back(move(p.second));
        return ans;
    
    }
};