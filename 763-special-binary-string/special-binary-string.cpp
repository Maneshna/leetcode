class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, start = 0;
        vector<string> specials;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;
            
            if (count == 0) {
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                specials.push_back("1" + inner + "0");
                start = i + 1;
            }
        }
        
        sort(specials.begin(), specials.end(), greater<string>());
        
        string result = "";
        for (string& sp : specials) result += sp;
        return result;
        
    }
};