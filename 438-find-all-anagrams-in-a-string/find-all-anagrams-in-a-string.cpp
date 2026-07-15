class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        int s_len = s.length();
        int p_len = p.length();

        if(p_len > s_len){
            return ans;
        }

        vector <int> p_count(26,0);
        vector <int> s_count(26,0);

        for(int i=0; i<p_len; i++){
            p_count[p[i] -'a']++;
            s_count[s[i] -'a']++;
        } 
        for (int i = p_len; i<s_len; i++){
            if(p_count == s_count){
                ans.push_back(i - p_len);
            }

            s_count[s[i] - 'a']++;
            s_count[s[i-p_len]-'a']--;
        }

        if(p_count == s_count){
            ans.push_back(s_len-p_len);
        }
        return ans;
        
    }
};