class Solution {
public:
    bool sumGame(string s) {
        double res = 0;
        double n = s.length();
        for (int i = 0; i < n; i++) {
            double sign;
            if (i < n / 2) {
                sign = 1;
            } else {
                sign = -1;
            }
            double value;
            if (s[i] == '?') {
                value = 4.5;
            } else {
                value = s[i] - '0';
            }
            res += sign * value;
        }
        if (res != 0.0) {
            return true;
        } else {
            return false;
        }
    }
};