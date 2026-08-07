class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> freq;
        vector<int>result;
        for(int x: bulbs){
            freq[x]++;

        }
        for(auto& entry: freq){
            if(entry.second%2 !=0){
                result.push_back(entry.first);
            }
        }
        return result;
        
    }
};