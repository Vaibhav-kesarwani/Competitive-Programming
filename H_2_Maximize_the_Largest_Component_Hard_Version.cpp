#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        for (int i = 0; i < h; i++)
        {
            cin >> s[i];
        }
        vector<int> cnt_row(h);
        vector<int> cnt_col(w);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '#')
                {
                    cnt_row[i] += 1;
                    cnt_col[j] += 1;
                }
            }
        }
        vector<vector<int>> ul(h, vector<int>(w));
        vector<vector<int>> ur(h, vector<int>(w));
        vector<vector<int>> dl(h, vector<int>(w));
        vector<vector<int>> dr(h, vector<int>(w));
        vector<vector<bool>> was(h, vector<bool>(w, false));
        int total = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '#' && !was[i][j])
                {
                    vector<pair<int, int>> que(1, {i, j});
                    was[i][j] = true;
                    int min_i = h + 1;
                    int min_j = w + 1;
                    int max_i = -1;
                    int max_j = -1;
                    for (int it = 0; it < int(que.size()); it++)
                    {
                        auto [qi, qj] = que[it];
                        min_i = min(min_i, qi);
                        min_j = min(min_j, qj);
                        max_i = max(max_i, qi);
                        max_j = max(max_j, qj);
                        for (int di = -1; di <= 1; di++)
                        {
                            for (int dj = -1; dj <= 1; dj++)
                            {
                                if (di * di + dj * dj == 1)
                                {
                                    int ni = qi + di;
                                    int nj = qj + dj;
                                    if (ni >= 0 && nj >= 0 && ni < h && nj < w)
                                    {
                                        if (s[ni][nj] == '#' && !was[ni][nj])
                                        {
                                            que.emplace_back(ni, nj);
                                            was[ni][nj] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    int sz = int(que.size());
                    total += sz;
                    dr[max_i][max_j] += sz;
                    dl[max_i][min_j] += sz;
                    ur[min_i][max_j] += sz;
                    ul[min_i][min_j] += sz;
                }
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i < h - 1)
                {
                    dr[i + 1][j] += dr[i][j];
                }
                if (j < w - 1)
                {
                    dr[i][j + 1] += dr[i][j];
                }
                if (i < h - 1 && j < w - 1)
                {
                    dr[i + 1][j + 1] -= dr[i][j];
                }
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = w - 1; j >= 0; j--)
            {
                if (i < h - 1)
                {
                    dl[i + 1][j] += dl[i][j];
                }
                if (j > 0)
                {
                    dl[i][j - 1] += dl[i][j];
                }
                if (i < h - 1 && j > 0)
                {
                    dl[i + 1][j - 1] -= dl[i][j];
                }
            }
        }
        for (int i = h - 1; i >= 0; i--)
        {
            for (int j = 0; j < w; j++)
            {
                if (i > 0)
                {
                    ur[i - 1][j] += ur[i][j];
                }
                if (j < w - 1)
                {
                    ur[i][j + 1] += ur[i][j];
                }
                if (i > 0 && j < w - 1)
                {
                    ur[i - 1][j + 1] -= ur[i][j];
                }
            }
        }
        for (int i = h - 1; i >= 0; i--)
        {
            for (int j = w - 1; j >= 0; j--)
            {
                if (i > 0)
                {
                    ul[i - 1][j] += ul[i][j];
                }
                if (j > 0)
                {
                    ul[i][j - 1] += ul[i][j];
                }
                if (i > 0 && j > 0)
                {
                    ul[i - 1][j - 1] -= ul[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int cur = total;
                if (i - 2 >= 0 && j - 2 >= 0)
                {
                    cur -= dr[i - 2][j - 2];
                }
                if (i + 2 < h && j - 2 >= 0)
                {
                    cur -= ur[i + 2][j - 2];
                }
                if (i - 2 >= 0 && j + 2 < w)
                {
                    cur -= dl[i - 2][j + 2];
                }
                if (i + 2 < h && j + 2 < w)
                {
                    cur -= ul[i + 2][j + 2];
                }
                cur += w - cnt_row[i];
                cur += h - cnt_col[j];
                cur -= (s[i][j] == '.');
                ans = max(ans, cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
