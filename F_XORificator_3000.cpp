#include <iostream>
using namespace std;
#define int uint64_t
#define SPEEDY std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
 
int xor_0_n(int n) {
    int rem = n % 4;
    if (rem == 0) {
        return n;
    }
    if (rem == 1) {
        return 1;
    }
    if (rem == 2) {
        return n + 1;
    }
    return 0;
}
 
int xor_range(int l, int r) {
    return xor_0_n(r) ^ xor_0_n(l - 1);
}
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, i, k;
        cin >> l >> r >> i >> k;
        int highBits = xor_range((l - k + (1 << i) - 1) >> i, (r - k) >> i) << i;
        int lowBits = k * (((r - k) / (1 << i) - (l - k - 1) / (1 << i)) & 1);
        cout << (xor_range(l, r) ^ highBits ^ lowBits) << '\n';
    }
    return 0;
}