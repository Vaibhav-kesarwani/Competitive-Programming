int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
int dd[10][2] {{0,0}, {0,0}, {0,1}, {1,1}, {0,2}, {2,1}, {4,1}, {3,1}, {0,3}, {1,2}};

inline void updt(int vs[], int d, int f) {
    int u = dd[d][0]; vs[u & 3] += f * dd[d][1];
    u >>= 2; vs[1] += f*u;
}

inline void inc(int vs[], int d) {
    int u = dd[d][0]; vs[u & 3] += dd[d][1];
    u >>= 2; vs[1] += u;
}

inline void dec(int vs[], int d) {
    int u = dd[d][0]; vs[u & 3] -= dd[d][1];
    u >>= 2; vs[1] -= u;
}

inline int req_size(int vs[]) {
    int n2 = max(0, vs[0]), n3 = max(0, vs[1]);
    int v2 = n2/3, r = n2%3 + (n3 & 1);
    return max(0, vs[3]) + max(0, vs[2]) + (n3 >> 1) + v2 + ((r + 1) >> 1);
}

vector<array<int, 10>> solve(int vs[], int n1) {
    vector<array<int, 10>> res;
    array<int,10> cur {};
    int n2 = max(0, vs[0]), n3 = max(0, vs[1]);
    cur[5] = max(0, vs[2]);
    cur[7] = max(0, vs[3]);
    cur[8] = n2/3; n2 %= 3;
    cur[9] = n3/2; n3 %= 2;
    cur[1] = max(0, n1);
    if (n2 == 0 && n3 == 0) {
        res.push_back(cur);
    } else if (n2 == 2 && n3 == 0) {
        cur[4] = 1; res.push_back(cur);
        if (cur[9]) { --cur[9]; cur[4] = 0; cur[6] = 2; res.push_back(cur); }
    } else if (n2 == 1 && n3 == 1) {
        cur[6] = 1; res.push_back(cur);
    } else if (n2 == 0 && n3 == 1) {
        cur[3] = 1; res.push_back(cur);
        if (cur[8]) {
            --cur[8]; cur[3] = 0; cur[4] = 1; cur[6] = 1; res.push_back(cur);
            if (cur[9]) { --cur[9]; cur[4] = 0; cur[6] = 3; res.push_back(cur); };
        }
    } else if (n2 == 1 && n3 == 0) {
        cur[2] = 1; res.push_back(cur);
        if (cur[9]) { --cur[9]; cur[2] = 0; cur[6] = 1; cur[3] = 1; res.push_back(cur); ++cur[9]; cur[3] = cur[6] = 0; }
        if (cur[8]) {
            --cur[8]; cur[2] = 0; cur[4] = 2; res.push_back(cur);
            if (cur[9]) { --cur[9]; cur[4] = 1; cur[6] = 2; res.push_back(cur); }
            if (cur[9]) { --cur[9]; cur[4] = 0; cur[6] = 4; res.push_back(cur); }
        }
    } else { // n0 == 2 && n3 == 1
        cur[2] = 1; cur[6] = 1; res.push_back(cur);
        cur[3] = 1; cur[4] = 1; cur[2] = 0; cur[6] = 0; res.push_back(cur);
        if (cur[9]) { --cur[9]; cur[4] = 0; cur[6] = 2; res.push_back(cur);  ++cur[9]; }
        if (cur[8]) {
            --cur[8]; cur[3] = 0; cur[4] = 2; cur[6] = 1; res.push_back(cur);
            if (cur[9]) { --cur[9]; cur[4] = 1; cur[6] = 3; res.push_back(cur); }
            if (cur[9]) { --cur[9]; cur[4] = 0; cur[6] = 5; res.push_back(cur); }
        }
    }
    return res;
}

class Solution {
public:
    string smallestNumber(string num, long long t) {
        int ns[4] {};
        while (!(t&1)) t >>= 1, ++ns[0];
        while (t % 3 == 0) t /= 3, ++ns[1];
        while (t % 5 == 0) t /= 5, ++ns[2];
        while (t % 7 == 0) t /= 7, ++ns[3];
        if (t != 1) return "-1";

        int N = size(num), i = 0, p0;
        if (req_size(ns) <= N)
        {
            int d[10] {};
            while (i < N && num[i] != '0') ++d[num[i++] - '0'];
            for (int x = 2; x < 10; ++x) updt(ns, x, -d[x]);
        }

        retry:
        while (1) {
            p0 = N - req_size(ns);
            if (i <= p0 || p0 < 0) break;
            while (i > p0) {
                int d = num[--i] - '0';
                inc(ns, d);
            }
        }
        //cout << i << " " << p0 << endl;
        if (i == N) return num;

        auto res = solve(ns, p0-i);
        
        if (p0 >= 0) {
            int t = num[i] - '0' + 1;
            while (t < 10) {
                bool found = false;
                for (auto &r : res) {
                    if (r[t]) found = true;
                    else if (!(t & 1) && r[t/2]) { --r[t/2]; ++r[t]; found = true; }
                    else if ((t % 3) == 0 && r[t/3]) { --r[t/3]; ++r[t]; found = true; }
                    else if (!(t & 3) && r[t/4]) { --r[t/4]; ++r[t]; found = true; }
                }
                if (found) break;
                ++t;
            }
            if (t < 10) {
                sort(begin(res), end(res));
                for (int u = size(res)-1; u >= 0; --u) {
                    auto &r = res[u];
                    if (!r[t]) continue;
                    num[i++] = '0' + t; --r[t];
                    for (int a = 1, aa = '1'; a < 10; ++a, ++aa)
                        for (int b = r[a]; b; --b) num[i++] = aa;
                    return num;
                }
            }
            while (--i >= 0 && num[i] == '9') ns[1] += 2;
            if (i >= 0) {
                inc(ns, num[i] - '0');
                dec(ns, ++num[i] - '0');
                num[++i] = '0';
                goto retry;
            }
            res = solve(ns, 0);
            res[0][1] = max(0, N+1 - accumulate(begin(res[0]), end(res[0]), 0));
        }

        string result(res[0][1], '1');
        for (int i = 2; i < 10; ++i)
            for (int t = res[0][i]; t; --t) result += char('0'+i);
        return result;
    }
};