using ll = long long;

class Solution {
public:
    long long countCommas(long long n) {
        ll store = n;

        ll ans{}, start = 1000, comma{1};

        while (start <= store) {
            ll end = start * 1000 - 1;
            ll up = min(end, store);

            if (up >= start) {
                ans += (up - start + 1) * comma;
            }

            start *= 1000;
            comma++;
        }

        return ans;
    }
};