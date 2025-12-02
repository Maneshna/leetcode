class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        for(int i =0; i<strs[0].size(); i++){
            char c = strs[0][i]; //we start the iteration from the first string value and map them
            for(int j = 1; j<strs.size(); j++){ //now this first string is compared with every other string in the array.
                if(i>=strs[j].size() || strs[j][i] !=c){ //is there is common and then suddenly the matching is stopped then we stop and print from 0 index to the i index where we iterated in the first place
                    return strs[0].substr(0, i );
                }
            }
        }
        return strs[0];
    }
};
