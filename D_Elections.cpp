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
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int nums, electionVote;
    cin >> nums >> electionVote;
    vector<int> givenVotes(nums);
    for (int i = 0; i < nums; i++) cin >> givenVotes[i];
    
    givenVotes[0] += electionVote;

    int givenTemp = 0, presetChk = givenVotes[0];
    for (int i = 0; i < givenVotes.size(); i++)
    {
        if (presetChk < givenVotes[i])
        {
            presetChk = givenVotes[i];
            givenTemp = i;
        }
    }
    int givenPresntVote = 0;
    vector<int> dontaedVote;
    for (auto i = 0; i < givenVotes.size(); i++)
    {
        givenPresntVote += givenVotes[i];
        if (!(i == givenTemp))
        {
            if (!(givenPresntVote >= presetChk)) dontaedVote.push_back(i + 1);
            else dontaedVote.push_back(i);
        }
        else dontaedVote.push_back(0);
    }
    for (auto &it : dontaedVote) cout << it << " ";
    cout nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}