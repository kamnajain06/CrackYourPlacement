class Solution {
public:
    bool fun(string& s, int numOps, int size, char demand) {
        int i = 0;
        while (i < s.length()) {
            if (s[i] != demand)
                numOps--; // demand not fulfilled
            demand ^= 1;  // always changing demand
            i++;
        }
        return numOps >= 0;
    }
    bool isPossible(string& s, int numOps, int size) {
        if (size == 1) {
            return fun(s, numOps, size, '0') || fun(s, numOps, size, '1');
        }
        int i = 1;
        int len = 1;
        char init = s[0];
        while (i < s.length()) {
            if (s[i] == init)
                len++;
            else {
                numOps -= (len / (size + 1));
                len = 1;
                init = s[i];
            }
            i++;
        }
        numOps -= (len / (size + 1));
        return numOps >= 0;
    }
    int minLength(string s, int numOps) {
        int n = s.length();
        int left = 1;
        int right = n;
        int ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(s, numOps, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};