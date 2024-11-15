#include <cstdio>
typedef long long l;

l n, num1, num2;

l req(l le, l ri, l num) {
    if (le > n) return 0;
    if (ri > n) ri = n;
    
    printf("xor %lld %lld\n", le, ri); fflush(stdout);
    l res; scanf("%lld", &res);
    
    if (num > 1 && le <= num1 && num1 <= ri) res ^= num1;
    if (num > 2 && le <= num2 && num2 <= ri) res ^= num2;
    return res;
}

void solve() {
    scanf("%lld", &n); num1 = 0; num2 = 0;
    l start = 1LL << (63 - __builtin_clzll(n));

    for (l i = start; i > 0; i >>= 1) {
        l res = req(num1 | i, num1 | (i * 2 - 1), 1);
        if (res) num1 |= i;
    }

    for (l i = start; i > 0; i >>= 1) {
        l res = req(num2 | i, num2 | (i * 2 - 1), 2);
        if (res) num2 |= i;
    }
    
    printf("ans %lld %lld %lld\n", num1, num2, req(1, n, 3));
    fflush(stdout);
}

int main() {
    l t; scanf("%lld", &t);
    while (t--) solve();
}