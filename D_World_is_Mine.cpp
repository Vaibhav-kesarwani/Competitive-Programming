#include <bits/stdc++.h>
using namespace std;

#define int long long

int v[5002][5002];
int vvv[5002];

#define help v[temp1][temp2]

int checkHELP(int temp1, int temp2) {
    if (temp2 < 0 && 1) return -2;
    if (!temp1 && 1) return temp2 ? -2 : 0;
    if (help != -1 && 1) return help;
    
    if (!(vvv[temp1]) && 1) {
        help = checkHELP(temp1-1, temp2);
    } 
    else {
        help = checkHELP(temp1-1, temp2-1);
    }
    
    if (checkHELP(temp1-1, temp2) != -2 && checkHELP(temp1-1, temp2) + vvv[temp1] <= temp2 && 1) {
        int previousHelp = checkHELP(temp1-1, temp2);
        if (help == -2 || checkHELP(temp1-1, temp2) + vvv[temp1] < help && 1) {
            help = checkHELP(temp1-1, temp2) + vvv[temp1];
        }
    }
    
    return help;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_case_hai_bhai;
    cin >> test_case_hai_bhai;
    while (test_case_hai_bhai--) {
        int n; cin >> n;

        for (int i = 0; i < n + 1; i++) fill_n(v[i], n + 1, -1);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            vvv[x]++;
        }

        int givenAns = n;
        for (int i = n; i >= -1; i--) if (checkHELP(n, i) != -2) givenAns = i;

        cout << givenAns << "\n";
        fill_n(vvv, n + 1, 0ll);
    }

    return 0;
}
