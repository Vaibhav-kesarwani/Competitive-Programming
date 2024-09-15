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
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> sequence(l);
    int i = 0;
    while (i < l)
    {
        cin >> sequence[i];
        i++;
    }

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    map<int, vector<pair<int, int>>> cells_by_value;

    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= m)
        {
            cin >> grid[row][col];
            switch (grid[row][col])
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                cells_by_value[grid[row][col]].emplace_back(row, col);
                break;
            default:
                break;
            }
            col++;
        }
        row++;
    }

    vector<vector<int>> future_possible(n + 2, vector<int>(m + 2, 0));

    i = 0;
    while (i < l)
    {
        vector<vector<int>> current_possible(n + 2, vector<int>(m + 2, 0));
        int value = sequence[i];

        int j = 0;
        while (j < cells_by_value[value].size())
        {
            auto &cell = cells_by_value[value][j];
            row = cell.first;
            int col = cell.second;
            if (!future_possible[row + 1][col + 1])
            {
                current_possible[row][col] = 1;
            }
            j++;
        }

        row = n;
        while (row >= 1)
        {
            int col = m;
            while (col >= 1)
            {
                current_possible[row][col] |= (row < n ? current_possible[row + 1][col] : 0) || (col < m ? current_possible[row][col + 1] : 0);
                col--;
            }
            row--;
        }

        future_possible = current_possible;
        i++;
    }

    cout << (future_possible[1][1] ? 'T' : 'N') << endl;
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
