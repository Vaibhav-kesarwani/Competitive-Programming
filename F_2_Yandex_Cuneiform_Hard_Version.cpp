#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <queue>
#include <fstream>
#include <random>
//#include <numbers>
#include <optional>
#include <deque>
#include <sstream>
#include <list>
#include <chrono>
#include <thread>
#include <cassert>
 
using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;
#define YN(b) if (b) cout << "YES\n"; else cout << "NO\n";
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) { for (auto &e: v) { is >> e; } return is; }
 
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) { for (auto &e: v) { os << e << " "; } return os; }
 
template<typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& v) { return is >> v.first >> v.second; }
 
template<typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V>& v) { return os << v.first << " " << v.second; }
 
const int64_t md = 1e9+7;

int dx[4] = {-1, 0, 1, 0};
 
inline int64_t sqr(int64_t x) {
    return x * x;
}
 
inline int popcount(int64_t x) {
    int c = 0;
    while (x) c += x & 1, x >>= 1;
    return c;
}
 
pair<int64_t, int64_t> inter(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}


struct pt {
    using T = int;
    using V = int64_t;
    T x = 0, y = 0;
    pt() = default;
    pt(T x, T y) : x(x), y(y) {}
    inline pt& operator-=(const pt& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline pt operator-(const pt& other) const {
        pt copy(*this);
        copy -= other;
        return copy;
    }
    inline pt& operator+=(const pt& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline pt operator+(const pt& other) const {
        pt copy(*this);
        copy += other;
        return copy;
    }
    V operator^(const pt& other) const {
        return (V)x * other.y - (V)y * other.x;
    }
    V operator*(const pt& other) const {
        return (V)x * other.x + (V)y * other.y;
    }
    void print() const {
        cerr << x << " " << y << "\n";
    }
    bool operator==(const pt&) const = default;
};


inline bool in_triangle(const pt& a, const pt& b, const pt& c, const pt& point) {
    int64_t s1 = abs((b - a) ^ (c - a));
    int64_t s2 = abs((a - point) ^ (b - point)) + abs((b - point) ^ (c - point)) + abs((c - point) ^ (a - point));
    return s1 == s2;
}

struct mi {
    size_t i = 0;
    size_t ni = 1;
    const size_t m;
    mi(size_t m) : m(m) {}
    void add() {
        ++i;
        if (++ni == m) ni = 0;
    }
};
int64_t orientation(pt a, pt b, pt c) {
    return -((int64_t)a.x * (b.y - c.y) + (int64_t)b.x * (c.y - a.y) + (int64_t)c.x * (a.y - b.y));
}
inline bool comp(pt a, pt b) {
    auto cp = a ^ b;
    if (!cp) {
        return a * a < b * b;
    }
    return (pt::V)a.x * b.x < 0 ? (a.x > b.x) : cp > 0;
}

struct NMP {
    array<pt, 13> pts;
    int len = 0;
    template<typename... Args>
    void emplace_back(Args&& ...p) {
        new (&pts[len++]) pt(p...);
    }
    void push_back(const pt& x) {
        pts[len++] = x;
    }
    pt& operator[](size_t x) {
        return pts[x];
    }
    size_t size() const {
        return len;
    }

    const pt& operator[](size_t x) const {
        return pts[x];
    }
    pt* begin() {
        return &pts[0];
    }
    pt* end() {
        return &pts[len];
    }
    void resize(size_t x) {
        len = x;
    }
};

struct poly {
    using P = pt;
    NMP pts;
    void add(const P& p) {
        pts.push_back(p);
    }
    
    template<typename... Args>
    void emplace(Args&& ...p) {
        pts.emplace_back(p...);
    }

    void sort() {
        size_t min_id = 0;
        for (size_t i = 1; i < pts.size(); ++i) {
            if (pts[i].y < pts[min_id].y || (pts[i].y == pts[min_id].y && pts[i].x < pts[min_id].x)) {
                min_id = i;
            }
        }
        std::rotate(pts.begin(), pts.begin() + min_id, pts.end());
        auto p0 = pts[0];
        std::sort(pts.begin(), pts.end(), [&](const P& a, const P& b) {
            auto o = orientation(p0, a, b);
            if (!o)
                return (int64_t)(p0.x-a.x)*(p0.x-a.x) + (int64_t)(p0.y-a.y)*(p0.y-a.y)
                    < (int64_t)(p0.x-b.x)*(p0.x-b.x) + (int64_t)(p0.y-b.y)*(p0.y-b.y);
            return o < 0;
        });
    }

    void no_coll() {
        if (pts.size() < 3) {
            return;
        }
        size_t ptr = 1;
        for (size_t j = 2; j < pts.size(); ++j) {
            if ((pts[ptr] - pts[ptr - 1]) ^ (pts[j] - pts[ptr])) {
                pts[++ptr] = pts[j];
                continue;
            }
            pts[ptr] = pts[j];
        }
        pts.resize(ptr + 1);
    }

    poly operator+(const poly& other) const {
        if (pts.size() == 1) {
            poly c(other);
            for (auto& p: c.pts) p += pts[0];
            return c;
        }
        if (other.pts.size() < pts.size()) {
            return other + *this;
        }
        // size at least 2s
        poly res;
        mi i(pts.size()), j(other.pts.size());

        while (i.i < pts.size() && j.i < other.pts.size()) {
            res.emplace(pts[i.i] + other.pts[j.i]);
            auto a = (pts[i.ni] - pts[i.i]);
            auto b = (other.pts[j.ni] - other.pts[j.i]);
            auto cp = a ^ b;
            if (cp < 0) {
                j.add();
            } else if (cp > 0) {
                i.add();
            } else if ((P::V)a.y * b.y >= 0) {
                i.add();
                j.add();
            } else if (a.y > b.y) {
                i.add();
            } else {
                j.add();
            }
        }
        while (i.i < pts.size()) {
            res.emplace(pts[i.i] + other.pts[0]);
            i.add();
        }
        
        while (j.i < other.pts.size()) {
            res.emplace(pts[0] + other.pts[j.i]);
            j.add();
        }
        
        res.no_coll();
        return res;
    }

    void print() {
        for (auto &e: pts) {
            cout << "(" << e.x << " " << e.y << ") ";
        }
        cout << "\n";
    }

    bool in(const pt& p) const {
        if (pts.size() == 1) {
            return pts[0] == p;
        }
        if (pts.size() == 2) {
            return ((pts[0] - p) ^ (pts[1] - p)) == 0 
                && min(pts[0].x, pts[1].x) <= p.x && p.x <= max(pts[0].x, pts[1].x)
                && min(pts[0].y, pts[1].y) <= p.y && p.y <= max(pts[0].y, pts[1].y);
        }
        for (int i = 2; i < pts.size(); ++i) {
            if (in_triangle(pts[i], pts[i - 1], pts[0], p)) {
                return true;
            }
        }
        return false;
    }
};


struct co {
    array<int, 3> cst {};
    poly p;
    co() {
        p.emplace(0, 0);
    }

    co(int l, int a, int b) {
        cst = {
            max(0, 1 + l - (a == 0) - (b == 0)) / 2,
            max(0, 1 + l - (a == 1) - (b == 1)) / 2,
            max(0, 1 + l - (a == 2) - (b == 2)) / 2
        };
        p.emplace(min(cst[0], l - cst[2]), max(0, l - cst[0] - cst[2]));
        p.emplace(min(cst[0], l), max(0, l - cst[0] - cst[2]));
        p.emplace(cst[0], min(cst[1], l - cst[0]));
        p.emplace(min(l - cst[1], cst[0]), cst[1]);
        p.emplace(max(0, l - cst[1] - cst[2]), min(l, cst[1]));
        p.emplace(max(0, l - cst[1] - cst[2]), min(cst[1], l - cst[2]));
        p.sort();
        p.no_coll();
    }

    co operator+(const co& rhs) {
        co res;
        res.p = p + rhs.p;
        for (int j = 0; j < 3; ++j) res.cst[j] = cst[j] + rhs.cst[j];
        return res;
    }

    bool ok(int x, int y, int z) {
        return x <= cst[0] && y <= cst[1] && z <= cst[2]; 
    }

    bool in(int x, int y, int z) {
        return ok(x, y, z) && p.in(pt(x, y));
    }
};

char idx[128]{};
string ydx = "YDX";

struct fenwick {
    fenwick(int x) : t(x), n(x) {}
    vector<int> t;
    int n;
    int sum (int r) {
        int result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            result += t[r];
        return result;
    }

    void inc (int i, int delta) {
        for (; i < n; i = (i | (i+1)))
            t[i] += delta;
    }
};

using S = std::list<pair<short, int>>;

struct cmp {
    bool operator()(S::iterator a, S::iterator b) const {
        return a->second < b->second;
    };
};

auto encode1(auto a, auto b) {
    return a * 256 + b;
};

auto encode(auto it) {
    auto prev = it++;
    return encode1(prev->first, it->first);
};

auto erase_char(auto& curr_pos, S& str, fenwick& alive, auto& pos, auto it) {
    auto curr = it;
    auto prev = --it;
    it = curr;
    auto next = ++it;
    if (next != str.end()) {
        if (!pos[encode(curr)].count(curr)) {
            exit(-1);
        }
        pos[encode(curr)].erase(curr);
    }
    if (prev != str.end()) {
        if (!pos[encode(prev)].count(prev)) {
            exit(-1);
        }
        pos[encode(prev)].erase(prev);
    }
    curr_pos.emplace_back(curr->first, alive.sum(curr->second) - 1);
    alive.inc(curr->second, -1);
    str.erase(curr);
    if (next != str.end() && prev != str.end()) {
        auto p = prev;
        ++p;
        if (p != next) {
            exit(-1);
        }
        pos[encode(prev)].emplace(prev);
    }
};

bool is_ok(S::iterator x, S::iterator end) {
    auto curr = x;
    auto prev = --x;
    auto next = ++curr;
    if (prev != end && next != end) {
        return prev->first != next->first;
    }
    return true;
}

auto got(auto& curr_pos, auto& str, auto& alive, auto& pos, vector<S::iterator> t) {
    for (auto &e: t) {
        erase_char(curr_pos, str, alive, pos, e);
    }
};


auto relax(auto& curr_pos, auto& str, auto& alive, auto& pos, short sym, short co) {
    auto &v = pos[co];
    auto it = *v.begin();
    auto A = it;
    auto prev = --it;
    it = A;
    auto B = ++it;
    auto next = ++it;
    if (prev != str.end() && next != str.end() && prev->first == next->first) {
        if (prev->first != sym) {
            exit(-1);
        }
        got(curr_pos, str, alive, pos, {prev, A, B});
        return false;
    }
    
    got(curr_pos, str, alive, pos, {A, B});
    return true;
};

vector<array<pair<char, int>, 3>> solve_str(const string& s) {
    S str;
    fenwick alive(s.size());

    for (int i = 0; i < s.size(); ++i) {
        str.emplace_back(s[i], i);
        alive.inc(i, 1);
    }

    auto it = str.begin();

    map<int, set<decltype(it), cmp>> pos;
    while (it != str.end()) {
        auto prev = it++;
        if (it == str.end()) break;
        pos[encode(prev)].emplace(prev);   
    }
    vector<pair<char, int>> curr_pos;
    vector<decltype(it)> curr_t;
    vector<array<pair<char, int>, 3>> res;
    while (str.size()) {
        it = str.begin();
        auto curr = it++;
        if (it == str.end()) {
            exit(-1);
        }
        short code = curr->first;
        erase_char(curr_pos, str, alive, pos, curr);

        array<int, 2> candidates;
        if (code == 'Y') {
            candidates[0] = encode1('D', 'X');
            candidates[1] = encode1('X', 'D');
        } else if (code == 'X') {
            candidates[0] = encode1('D', 'Y');
            candidates[1] = encode1('Y', 'D');
        } else {
            candidates[0] = encode1('Y', 'X');
            candidates[1] = encode1('X', 'Y');
        }
        bool ok = 0;
        while (!ok) {
            for (auto &c: candidates) {
                if (!pos[c].size()) {
                    continue;
                }
                if (relax(curr_pos, str, alive, pos, code, c)) {
                    ok = 1;
                    res.emplace_back();
                    res.back()[0] = curr_pos[2];
                    res.back()[1] = curr_pos[1];
                    res.back()[2] = curr_pos[0];
                    curr_pos.clear();
                    break;
                }
                // A...ABCA, ABC removed
                res.emplace_back();
                for (int j = 0; j < 3; ++j) {
                    res.back()[j] = curr_pos.back(); // removed
                    res.back()[j].second += 1;
                    curr_pos.pop_back();
                }
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

bool check(const string& s) {
    array<int, 3> cnt{};
    char prev = -1;
    for (auto &e: s) {
        if (e == '?') {
            return false;
        }
        if (e != 'Y' && e != 'D' && e != 'X') {
            return false;
        }
        if (e == prev) return false;
        prev = e;
        ++cnt[idx[e]];
    }
    return cnt[0] == s.size() / 3 && cnt[1] == s.size() / 3 && cnt[2] == s.size() / 3;
}

optional<string> solve_fast1(string v) {
    auto sv = v;
    int N = v.size() / 3;
    array<int, 3> rem{N, N, N};
    for (auto &e: v) {
        if (e == '?') continue;
        --rem[idx[e]];
    }
    if (rem[0] < 0 || rem[1] < 0 || rem[2] < 0) return {};
    vector<co> mink;
    vector<pair<int, int>> segs;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != '?') continue;
        int j = i + 1;
        while (j < v.size() && v[j] == '?') ++j;
        mink.emplace_back(j - i, i > 0 ? idx[v[i - 1]] : 3, j < v.size() ? idx[v[j]] : 3);
        segs.emplace_back(i, j - 1);
        i = j - 1;
    }
    reverse(mink.begin(), mink.end());
    reverse(segs.begin(), segs.end());
    for (int i = 1; i < mink.size(); ++i) {
        mink[i] = mink[i - 1] + mink[i];
    }
    if (mink.size()) {
        mink.pop_back();
    }
    while (segs.size()) {
        auto seg = segs.back();
        segs.pop_back();
        auto mk = mink.size() ? mink.back() : co();
        if (mink.size()) {
            mink.pop_back();
        }
        char prev = idx[seg.first ? v[seg.first - 1] : '?'];
        char next_r = idx[seg.second + 1 < v.size() ? v[seg.second + 1] : '?'];
        while (seg.first <= seg.second) {
            char next = seg.first == seg.second ? next_r : -1;
            bool found = 0;
            for (int j = 0; j < 3; ++j) {
                if (prev == j || next == j || !rem[j]) {
                    continue;
                }
                --rem[j];
                auto cs = co(seg.second - seg.first, j, seg.second + 1 < v.size() ? idx[v[seg.second + 1]] : 3);
                auto vv = mk + cs;
                if (!vv.in(rem[0], rem[1], rem[2])) {
                    ++rem[j];
                    continue;
                }
                v[seg.first++] = ydx[j];
                prev = j;
                found = 1;
                break;
            }
            if (!found) {
                return {};
            }
        }
    }
    return v;
}

optional<pair<vector<array<pair<char, int>, 3>>, string>> solve(string s) {
    auto ww = solve_fast1(s);
    if (!ww || !check(*ww)) {
        return {};
    }
    return pair{solve_str(*ww), *ww};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    idx['Y'] = 0;
    idx['D'] = 1;
    idx['X'] = 2;
    idx['?'] = 99;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        auto r = solve(s);
        if (r) {
            cout << "YES\n" << r->second << "\n";
            for (auto &x: r->first) {
                for (auto &e: x) {
                    cout << e.first << " " << e.second << " ";
                }
                cout << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}