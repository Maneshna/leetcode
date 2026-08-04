class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }
        //store in vector and sort them
        vector<pair<int,char>> vec;

        for(auto& [ch, count]: freq){
            vec.push_back({count, ch});
        }
        sort(vec.rbegin(), vec.rend());

        string result="";
        //store back in string

        for(auto& [count, ch]: vec){
            result.append(count, ch);
        }
        return result;

        
    }
};