class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorR = start^goal;
        int count = __builtin_popcount(xorR);
        return count;
    }
};