class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freqofnums;
        unordered_map<int,int> freqoffreq;

        for(int x: nums){
            freqofnums[x]++;
        }

        for(auto& entry: freqofnums){
            freqoffreq[entry.second]++;
        }

        for(int x : nums){
            if(freqoffreq[freqofnums[x]]==1){
                return x;
            }
        }
        return -1;
        
    }
};