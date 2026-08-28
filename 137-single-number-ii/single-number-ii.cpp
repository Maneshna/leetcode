class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int num: nums){
            map[num]++;
        }
        for(auto const& [num, count] : map){
            if(count==1){
                return num;
            }
        }
        return -1;



        
    }
};