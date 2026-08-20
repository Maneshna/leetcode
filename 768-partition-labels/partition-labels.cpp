class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26,0);
        for(int i =0;i<s.length();i++){
            lastIndex[s[i]-'a']=i;
        }
        vector<int> result;
        int start = 0;
        int max_reach =0;

        for(int i =0;i<s.length();i++){
            max_reach = max(max_reach, lastIndex[s[i]-'a']);

            if(i==max_reach){
                result.push_back(i-start+1);
                start = i+1; //new start point
            }
        }
        return result;
        
    }
};