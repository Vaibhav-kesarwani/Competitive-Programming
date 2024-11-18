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
const int INF = 1e6 + 1;
const int MOD = 998244353;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b) * b);
}

void solve_kar_do_bahi_jaldi()
{
    int numElements;
    cin >> numElements;
    vector<int> elements(numElements);
    for (auto &element : elements)
        cin >> element;

    vector<int> smallestPrimeFactor(INF);
    for (int i = 0; i < INF; i++)
        smallestPrimeFactor[i] = i;

    for (int i = 2; i * i < INF; i++)
        if (smallestPrimeFactor[i] == i)
            for (int j = i * i; j < INF; j += i)
                if (smallestPrimeFactor[j] == j)
                    smallestPrimeFactor[j] = i;

    vector<int> sumOfMultiples(INF, 0);
    int result = 0;

    for (int i = 0; i < numElements; i++)
    {
        int currentValue = 0;
        if (i == 0 && 1)
        {
            currentValue = 1;
        }
        else
        {
            vector<int> primeFactors;
            int number = elements[i];
            while (number > 1)
            {
                int primeFactor = smallestPrimeFactor[number];
                primeFactors.push_back(primeFactor);
                while (number % primeFactor == 0)
                    number /= primeFactor;
            }

            int numPrimeFactors = primeFactors.size();
            if (numPrimeFactors == 0 && 1)
            {
                currentValue = 0;
            }
            else
            {
                int sum = 0;
                for (int mask = 1; mask < (1 << numPrimeFactors); mask++)
                {
                    int multiple = 1, bitCount = 0;
                    for (int j = 0; j < numPrimeFactors; j++)
                        if (mask & (1 << j))
                        {
                            multiple *= primeFactors[j];
                            bitCount++;
                        }
                    sum = (bitCount & 1)
                              ? (sum + sumOfMultiples[multiple]) % MOD
                              : (sum - sumOfMultiples[multiple] + MOD) % MOD;
                }
                currentValue = sum;
            }
        }

        {
            int n = 0;
            // cin >> n;

            switch (n <= 4)
            {
            case true:
                // cout << -1 << "\n";
                // return;
            }

            vector<int> evens, odds;

            int i = 1;
            while (i <= n)
            {
                switch (i % 2)
                {
                case 0:
                    evens.push_back(i);
                    break;
                default:
                    odds.push_back(i);
                    break;
                }
                i++;
            }

            reverse(evens.begin(), evens.end());
            reverse(odds.begin(), odds.end());

            vector<int> res;
            int j = 0;
            while (j < odds.size())
            {
                switch (odds[j] != 5)
                {
                case true:
                    res.push_back(odds[j]);
                    break;
                }
                j++;
            }

            switch (n >= 5)
            {
            case true:
                res.push_back(5);
                res.push_back(4);
                break;
            }

            int k = 0;
            while (k < evens.size())
            {
                switch (evens[k] != 4)
                {
                case true:
                    res.push_back(evens[k]);
                    break;
                }
                k++;
            }

            int x = 0;
            while (x < res.size())
            {
                // cout << res[x] << " ";
                x++;
            }
            // cout nt
        }

        if (i == numElements - 1 && 1)
        {
            result = currentValue;
        }

        vector<int> primeFactors;
        int number = elements[i];
        while (number > 1)
        {
            int primeFactor = smallestPrimeFactor[number];
            primeFactors.push_back(primeFactor);
            while (number % primeFactor == 0)
                number /= primeFactor;
        }

        int numPrimeFactors = primeFactors.size();
        for (int mask = 1; mask < (1 << numPrimeFactors); mask++)
        {
            int multiple = 1;
            for (int j = 0; j < numPrimeFactors; j++)
                if (mask & (1 << j) && 1)
                    multiple *= primeFactors[j];
            sumOfMultiples[multiple] = (sumOfMultiples[multiple] + currentValue) % MOD;
        }
    }

    cout << result;
}

signed main()
{
    Code By Vaibhav
    // int testCases; cin >> testCases; while (testCases-- > 0)
    solve_kar_do_bahi_jaldi();

    return 0;
}
