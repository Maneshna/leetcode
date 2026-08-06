class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //create a vector to count the freq
        vector<int> freq(26,0);

        for(char task:tasks){

            freq[task - 'A']++;
        }
        int maxfreq = *max_element(freq.begin(), freq.end());
        //now find how many have max freq
        int maxcount =0;
        for(int f:freq){
            if(f==maxfreq){
                maxcount++;
            }
        }

        int ans = max((int)tasks.size(), (maxfreq-1)*(n+1)+maxcount);
        return ans;
        
    }
};