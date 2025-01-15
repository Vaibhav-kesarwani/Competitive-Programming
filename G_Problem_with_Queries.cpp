#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
}
using ll = long long;

const int kN = 1e5 + 5;
const int kB = 350, kC = kN / kB + 5;
int n, q;
array<int, kN> a, buc, bel;
array<array<int, kC>, kN> cnt;

struct BIT
{
    array<ll, kC> tr;
    BIT() { tr.fill(0); }
    void Update(int x, ll v)
    {
        for (; x < kC; x += (x & -x))
            tr[x] += v;
    }
    ll Query(int x)
    {
        ll ans = 0;
        for (; x; x -= (x & -x))
            ans += tr[x];
        return ans;
    }
};
array<BIT, kC> val;

void Build()
{
    for (int b = 1, l = 1, r = kB; l <= n; b++, l += kB, r += kB)
    {
        r = min(r, n);
        ll sum = 0;
        for (int i = l; i <= r; i++)
            sum += buc[a[i]]++;
        val[b].Update(b, sum);
        for (int bb = b + 1, p = l + kB, q = r + kB; p <= n; bb++, p += kB, q += kB)
        {
            q = min(q, n), sum = 0;
            for (int i = p; i <= q; i++)
                sum += buc[a[i]];
            val[b].Update(bb, sum);
        }
        buc.fill(0);
    }
    for (int b = 1, l = 1, r = kB; l <= n; b++, l += kB, r += kB)
    {
        r = min(r, n);
        for (int i = l; i <= r; i++)
            buc[a[i]]++;
        for (int i = 1; i <= n; i++)
            cnt[i][b] = buc[i];
    }
    buc.fill(0);
}

void Modify(int x, int v, int coef)
{
    int b = bel[x];
    for (int i = b; i <= bel[n]; i++)
        cnt[v][i] += coef;
    for (int i = b + 1; i <= bel[n]; i++)
    {
        val[b].Update(i, coef * (cnt[v][i] - cnt[v][i - 1]));
    }
    for (int i = 1; i < b; i++)
    {
        val[i].Update(b, coef * (cnt[v][i] - cnt[v][i - 1]));
    }
}

void Rebuild(int b)
{
    val[b].Update(b, -val[b].Query(b));
    int l = (b - 1) * kB + 1, r = min(b * kB, n);
    ll sum = 0;
    for (int i = l; i <= r; i++)
        sum += buc[a[i]]++;
    val[b].Update(b, sum);
    for (int i = l; i <= r; i++)
        buc[a[i]]--;
}

void Update(int x, int nw)
{
    Modify(x, a[x], -1), Modify(x, a[x] = nw, 1);
    Rebuild(bel[x]);
}

ll Brute(int l, int r)
{
    ll ans = 0;
    for (int i = l; i <= r; i++)
        ans += buc[a[i]]++;
    for (int i = l; i <= r; i++)
        buc[a[i]]--;
    return ans;
}

int Get(int b, int x)
{
    int c = 0;
    for (int i = 1; i <= min(n, b * kB); i++)
    {
        c += (a[i] == x);
    }
    return c;
}

ll Query(int l, int r)
{
    int bl = bel[l], br = bel[r];
    if (bl == br)
        return Brute(l, r);
    ll ans = 0;
    for (int i = bl + 1; i < br; i++)
        ans += val[i].Query(br - 1);
    for (int i = l; i <= bl * kB; i++)
    {
        ans += buc[a[i]]++ + (cnt[a[i]][br - 1] - cnt[a[i]][bl]);
    }
    for (int i = (br - 1) * kB + 1; i <= r; i++)
    {
        ans += buc[a[i]]++ + (cnt[a[i]][br - 1] - cnt[a[i]][bl]);
    }
    for (int i = l; i <= bl * kB; i++)
        buc[a[i]]--;
    for (int i = (br - 1) * kB + 1; i <= r; i++)
        buc[a[i]]--;
    return ans;
}

int main()
{
    // file();
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        bel[i] = (i - 1) / kB + 1;
    Build();
    cin >> q;
    for (ll lst = 0, op, x, y; q--;)
    {
        cin >> op >> x >> y;
        x = (x + lst) % n + 1, y = (y + lst) % n + 1;
        if ((op == 2) && (x > y))
            swap(x, y);
        if (op == 1)
            Update(x, y);
        else
        {
            ll ans = Query(x, y), len = y - x + 1;
            cout << (lst = len * (len - 1) / 2 - ans) << " ";
        }
    }
    cout << "\n";
    return 0;
}