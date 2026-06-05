class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto neg_end=lower_bound(nums.begin(), nums.end(), 0);
        int neg_count= distance(nums.begin(), neg_end);

        auto pos_start=upper_bound(nums.begin(), nums.end(), 0);
        int pos_count=distance(pos_start, nums.end());

        return max(neg_count, pos_count);

        
    }
};