#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n; cin >> n;
    string s; cin >> s;

    switch (n % 2) {
        case 0: {
            unordered_map<char, int> even_counter;
            unordered_map<char, int> odd_counter;
            int i = 0;
            while (i < s.length()) {
                ((i % 2 == 0) ? even_counter : odd_counter)[s[i]]++;
                i++;
            }

            int even_max_count = 0;
            auto it = even_counter.begin();
            while (it != even_counter.end()) {
                if (it->second > even_max_count) {
                    even_max_count = it->second;
                }
                it++;
            }

            int odd_max_count = 0;
            it = odd_counter.begin();
            while (it != odd_counter.end()) {
                if (it->second > odd_max_count) {
                    odd_max_count = it->second;
                }
                it++;
            }

            cout << (n / 2 - even_max_count) + (n / 2 - odd_max_count) << endl;
            break;
        }

        case 1: {
            switch (n) {
                case 1: {
                    cout << 1 << endl;
                    return;
                }

                default: {
                    int best = numeric_limits<int>::max();
                    unordered_map<char, int> even_counter;
                    unordered_map<char, int> odd_counter;
                    int i = 0;
                    while (i < n - 1) {
                        ((i % 2 == 0) ? even_counter : odd_counter)[s[i]]++;
                        i++;
                    }

                    unordered_map<char, int> even_counter_after;
                    unordered_map<char, int> odd_counter_after;
                    int even_max_count = 0;
                    auto it = even_counter.begin();
                    while (it != even_counter.end()) {
                        even_max_count = max(even_max_count, it->second);
                        it++;
                    }

                    int odd_max_count = 0;
                    it = odd_counter.begin();
                    while (it != odd_counter.end()) {
                        odd_max_count = max(odd_max_count, it->second);
                        it++;
                    }

                    best = min(best, (n / 2) - even_max_count + (n / 2) - odd_max_count);

                    i = n - 2;
                    while (i >= 0) {
                        if (i % 2 == 0) {
                            even_counter[s[i]]--;
                            even_counter_after[s[i + 1]]++;
                        } else {
                            odd_counter[s[i]]--;
                            odd_counter_after[s[i + 1]]++;
                        }

                        unordered_map<char, int> even_counter_merged = even_counter;
                        auto jt = even_counter_after.begin();
                        while (jt != even_counter_after.end()) {
                            even_counter_merged[jt->first] += jt->second;
                            jt++;
                        }

                        unordered_map<char, int> odd_counter_merged = odd_counter;
                        jt = odd_counter_after.begin();
                        while (jt != odd_counter_after.end()) {
                            odd_counter_merged[jt->first] += jt->second;
                            jt++;
                        }

                        even_max_count = 0;
                        it = even_counter_merged.begin();
                        while (it != even_counter_merged.end()) {
                            even_max_count = max(even_max_count, it->second);
                            it++;
                        }

                        odd_max_count = 0;
                        it = odd_counter_merged.begin();
                        while (it != odd_counter_merged.end()) {
                            odd_max_count = max(odd_max_count, it->second);
                            it++;
                        }

                        best = min(best, (n / 2) - even_max_count + (n / 2) - odd_max_count);

                        i--;
                    }

                    cout << (n < 2 ? best + 2 : best + 1) nt
                    break;
                }
            }
            break;
        }
    }
}

signed main() {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya > 0) {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
        Bhai_Test_Case_Hai_Ya--;
    }

    return 0;
}
