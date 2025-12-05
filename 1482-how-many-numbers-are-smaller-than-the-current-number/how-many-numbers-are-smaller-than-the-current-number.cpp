class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int>freq(101,0);
        for(int x:nums){
            freq[x]++;
        }
        for(int i = 1; i<101;i++){
            freq[i] +=freq [i-1];
        }
        vector<int>result;
        for(int x:nums){
            if(x==0) result.push_back(0);
            else result.push_back(freq[x-1]);
        }
        return result;
    }
};