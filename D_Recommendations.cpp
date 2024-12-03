#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

const int MAX = 2e5;

iii a[MAX + 5];
int t, n;
ll kq[MAX + 5];

int main() {
    if(fopen("Recommendations.inp","r")) {
        freopen("Recommendations.inp","r",stdin);
        freopen("Recommendations.out","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) kq[i] = 0;
        for(int i = 1; i <= n; ++i) {
            int l, r;
            cin >> l >> r;
            a[i] = iii(ii(l, r), i);
        }
        sort(a + 1, a + n + 1, [](iii x, iii y) {
            return ii(x.fi.se, -x.fi.fi) > ii(y.fi.se, -y.fi.fi);
        });
        set<int> s;
        for(int i = 1; i <= n; ++i) {
            if(a[i].fi == a[i + 1].fi && i < n) {
                while(a[i].fi == a[i + 1].fi && i < n) ++i;
                s.insert(a[i].fi.fi);
                continue;
            }
            auto it = s.upper_bound(a[i].fi.fi);
            if(it!=s.begin()) {
                --it;
                kq[a[i].se] += abs(a[i].fi.fi - *it);
            }
            s.insert(a[i].fi.fi);
        }
        sort(a + 1, a + n + 1, [](iii x, iii y) {
            return ii(x.fi.fi, -x.fi.se) < ii(y.fi.fi, -y.fi.se);
        });
        s.clear();
//        for(int i = 1; i <= n; ++i) cout << a[i].fi.fi << " " << a[i].fi.se << "\n";
        for(int i = 1; i <= n; ++i) {
            if(a[i].fi == a[i + 1].fi && i < n) {
                while(a[i].fi == a[i + 1].fi && i < n) ++i;
                s.insert(a[i].fi.se);
                continue;
            }
            auto it = s.lower_bound(a[i].fi.se);
//            cout << i << " ";
            if(it != s.end()) {
                kq[a[i].se] += abs(a[i].fi.se - *it);
            }
            s.insert(a[i].fi.se);
        }
        for(int i = 1; i <= n; ++i) cout << kq[i] << "\n";
    }
}
