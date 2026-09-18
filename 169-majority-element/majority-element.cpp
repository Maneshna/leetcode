class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //make a map to count the element that appears more then n/2 times
        unordered_map<int, int> freq;
        int n =nums.size();
        for(int num: nums){
            freq[num]++;
            if(freq[num]>n/2){
                return num;
            }
        }
        return 0;
        
        
    }
};