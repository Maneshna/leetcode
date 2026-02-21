class Solution {
public:

int countPrimeSetBits(int left, int right) {
        int cntPrimeSetBits = 0;
        // The mask represents primes: 2, 3, 5, 7, 11, 13, 17, 19
        // Binary: 010100010100010101100
        int magicMask = 665772; 

        for (int num = left; num <= right; num++) {
            // Check if the bit at the position of the set bit count is 1
            if ((magicMask >> __builtin_popcount(num)) & 1) {
                cntPrimeSetBits++;
            }
        }
        return cntPrimeSetBits;
    }
};
