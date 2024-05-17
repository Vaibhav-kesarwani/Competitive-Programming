#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Vaibhav cout.tie(NULL);
#define nt <<"\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const long long INF = LONG_LONG_MAX;
const long long mod = 1000000007;


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int hour, minute; char colan; cin >> hour >> colan >> minute;

    string am_pm = (hour < 12 ? "AM" : "PM");
    hour = (hour % 12 ? hour % 12 : 12);

    cout << (hour < 10 ? "0" : "") << hour << colan << (minute < 10 ? "0" : "") << minute << " " << am_pm nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}