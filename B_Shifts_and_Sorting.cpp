#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();  // To ignore the newline character after the integer input
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        
        std::vector<int> vec(s.size());
        std::transform(s.begin(), s.end(), vec.begin(), [](char c) { return c - '0'; });
        
        int zeroes = std::count(vec.begin(), vec.end(), 0);
        int cnt[2] = {0, 0};
        long long ans = 0;

        for (int c : vec) {
            cnt[c]++;
            if (c == 0)
                ans += (cnt[1] > 0) ? 1 : 0;
            else
                ans += (zeroes - cnt[0]);
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
