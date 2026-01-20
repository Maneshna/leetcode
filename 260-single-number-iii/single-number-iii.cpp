class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) {
            xorAll ^= x;
        }

        // convert to unsigned to avoid overflow
        unsigned int ux = static_cast<unsigned int>(xorAll);
        unsigned int diffBit = ux & (~ux + 1);

        int a = 0, b = 0;
        for (int x : nums) {
            if (x & diffBit)
                a ^= x;
            else
                b ^= x;
        }

        return {a, b};
    }
};