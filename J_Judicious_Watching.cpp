#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define sz(a) ((int) (a).size())
#define pb emplace_back
#define me(a, x) memset(a, x, sizeof(a))
#define vi vector<int>
#define ull unsigned long long
using namespace std;
#define pii pair<int,int>
const int N = 5e5 + 7;
int n, m, q;
ll a[N], d[N], l[N];
pair<ll,ll>f[N];
ll prec[N];
ll S[N];
void Main() {
    cin >> n >> m >> q;
    L(i, 1, n) {
        cin >> f[i].second;
    }
    L(i, 1, n) {
        cin >> f[i].first;
    }
    L(i, 1, m) {
        cin >> l[i];
    }
    sort(f + 1, f + n + 1);
    vector<pair<ll,ll>>inter;
    ll cur = 1e18;
    R(i, n, 1) {
        // cout << f[i].first << ' ' << f[i].second << endl;
        cur = min(cur, f[i].first);
        // cout << cur - f[i].second << ' ' << cur << endl;
        inter.pb(cur - f[i].second, cur);
        cur -= f[i].second;
    }
    sort(inter.begin(), inter.end());
    L(i, 1, n) {
        prec[i] = prec[i - 1] + inter[i - 1].second - inter[i - 1].first;
        // cout << "prec = " << prec[i] << endl;
        // cout << inter[i].first << ' ' << inter[i].second << endl;
    }
    L(i, 1, m) {
        S[i] = S[i - 1] + l[i];
    }
    while(q--) {
        ll t;
        cin >> t;
        int p = lower_bound(inter.begin(), inter.end(), make_pair(t, (ll)1e18)) - inter.begin();
        if(p) {
            --p;
            if(inter[p].second > t) {
                t = inter[p].first;
                --p;
            }
            t -= prec[p + 1];
        }
        // cout << "t = " << t << endl;
        ll val = upper_bound(S + 1, S + m + 1, t) - S - 1;
        cout << val << ' ';
    }
    cout << '\n';
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) Main();
    return 0;
}