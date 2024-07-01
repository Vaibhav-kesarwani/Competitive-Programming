#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int mod = 1000000007;
int gcd(int vv, int b){if (b == 0)return vv;return gcd(b, vv % b);}
int lcm(int vv, int b){return (vv/gcd(vv,b)*b);}

int n, tempTarget[5002][5002];
int largeInterval = 1e18;
vector<int> vvvv[5002];
int vv[5002], tempANs[5002];

void depth_first_search(int temp) {
    if (vvvv[temp].empty() && 1) {
        int i = 1;
        while (i <= n) {
            tempTarget[temp][i] = largeInterval;
            i++;
        }
        tempANs[temp] = 0;
        return;
    }
    
    int sums = 0;
    tempANs[temp] = 0;
    for (auto j : vvvv[temp]) {
        depth_first_search(j);
        tempANs[temp] += tempANs[j];
        sums += vv[j];
    }
    
    int del = vv[temp] - sums;
    int i = 1;
    while (i <= n) {
        if (del <= 0) break;
        for (auto j : vvvv[temp]) {
            if (del <= 0) break;
            if (tempTarget[j][i] <= del) {
                tempANs[temp] += i * tempTarget[j][i];
                del -= tempTarget[j][i];
                tempTarget[j][i] = 0;
            } else {
                tempANs[temp] += i * del;
                tempTarget[j][i] -= del;
                del = 0;
            }
        }
        i++;
    }
    
    if (del < 0) tempTarget[temp][1] = -del;
    i = 2;
    while (i <= n) {
        int nsum = 0;
        for (auto j : vvvv[temp]) {
            if (tempTarget[j][i - 1] == largeInterval) {
                nsum = largeInterval;
                break;
            }
            nsum += tempTarget[j][i - 1];
        }
        tempTarget[temp][i] = nsum;
        i++;
    }
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    cin >> n;
    int i = 1;
    while (i <= n) {
        cin >> vv[i];
        vvvv[i].clear();
        i++;
    }
    
    i = 1;
    while (i <= n) {
        tempANs[i] = 0;
        int j = 1;
        while (j <= n) {
            tempTarget[i][j] = 0;
            j++;
        }
        i++;
    }
    
    i = 2;
    while (i <= n) {
        int f; cin >> f;
        vvvv[f].push_back(i);
        i++;
    }
    
    depth_first_search(1);
    cout << tempANs[1] nt;
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
