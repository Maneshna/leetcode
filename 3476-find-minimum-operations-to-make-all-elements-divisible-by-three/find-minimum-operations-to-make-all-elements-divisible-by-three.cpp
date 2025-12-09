class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
    for (int x : nums) {
        if (x % 3 != 0) {
            count++;   // needs exactly 1 operation
        }
    }
    return count;
    }
};