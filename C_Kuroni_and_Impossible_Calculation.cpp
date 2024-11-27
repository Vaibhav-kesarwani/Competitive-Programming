#include <bits/stdc++.h>

using namespace std;

int p;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n>>p;
    if (n>p) {cout<<0; return 0;}
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    int res = 1;
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++) res = mul(res, abs(a[i] - a[j])%p);
    cout<<res;
}