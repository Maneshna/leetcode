class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //we will make two of the maps to map both the strings

        if(s1.length() > s2.length()){
            return false;
        }
        unordered_map<char,int> s1map;
        unordered_map<char,int> windowmap;

        //map the s1 in s1map
        for(char c: s1){
            s1map[c]++;
        }
        //map the first frequency of the window made in s2
        int k = s1.length();
        for(int i=0;i<k;i++){
            windowmap[s2[i]]++;
        }
        if(windowmap == s1map) return true;

        //now slide the window
        for(int right = k; right<s2.length(); right++){
            windowmap[s2[right]]++;
            char leftchar = s2[right-k];
            windowmap[leftchar]--;
            if(windowmap[leftchar]==0) windowmap.erase(leftchar);
            if(windowmap == s1map) return true;
        }
        return false;
    }
};