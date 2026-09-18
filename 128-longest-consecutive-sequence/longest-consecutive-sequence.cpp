class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //we will make unordred set
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen =0;
        for(int num: st){
            if(st.find(num-1) == st.end()){
                int currentNum = num;
                int currentStreak =1;
                while(st.find(currentNum+1) != st.end()){
                    currentNum++;
                    currentStreak++;
                }
                maxLen = max(maxLen, currentStreak);
            }
        }
        return maxLen;
        
    }
};