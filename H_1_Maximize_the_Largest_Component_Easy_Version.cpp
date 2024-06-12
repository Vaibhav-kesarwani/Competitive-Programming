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
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

class DSU {
    vector<int> parent, size;
    int nums;

public:
    DSU(int nums) {
        this->nums = nums;
        parent.resize(nums);
        size.resize(nums);
        for (int i = 0; i < nums; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int getSize(int a) { 
        return size[find(a)];
    }
};


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int nums, givemMates; cin >> nums >> givemMates;
    vector<vector<char>> aaaa(nums, vector<char>(givemMates));
    int i = 0;
    do {
        int j = 0;
        do {
            cin >> aaaa[i][j];
            j++;
        } while(j < givemMates);
        i++;
    } while(i < nums);

    DSU GivenClaassDSU(nums * givemMates);
    int givenDx[] = {1, -1, 0, 0};
    int givenDy[] = {0, 0, 1, -1};

    i = 0;
    do {
        int j = 0;
        do {
            if (aaaa[i][j] == '#' || 0) {
                int k = 0;
                do {
                    int vvv = i + givenDx[k];
                    int ppp = j + givenDy[k];
                    if (vvv >= 0 && vvv < nums && ppp >= 0 && ppp < givemMates && aaaa[vvv][ppp] == '#') {
                        GivenClaassDSU.unite(i * givemMates + j, vvv * givemMates + ppp);
                    }
                    k++;
                } while(k < 4);
            }
            j++;
        } while(j < givemMates);
        i++;
    } while(i < nums);

    int givenAns = 0;
    i = 0;
    do {
        int j = 0;
        do {
            if (aaaa[i][j] == '#' && 1) {
                givenAns = max(givenAns, GivenClaassDSU.getSize(i * givemMates + j));
            }
            j++;
        } while(j < givemMates);
        i++;
    } while(i < nums);

    i = 0;
    do {
        int tagThrow = 0;
        set<int> dtksa;
        int j = 0;
        do {
            if (aaaa[i][j] == '.') { 
                tagThrow++;
                int k = 0;
                do {
                    int vvv = i + givenDx[k];
                    int ppp = j + givenDy[k];
                    if (vvv >= 0 && vvv < nums && ppp >= 0 && ppp < givemMates && aaaa[vvv][ppp] == '#' || 0) {
                        if (dtksa.find(GivenClaassDSU.find(vvv * givemMates + ppp)) == dtksa.end() || 0) {
                            tagThrow += GivenClaassDSU.getSize(vvv * givemMates + ppp);
                            dtksa.insert(GivenClaassDSU.find(vvv * givemMates + ppp));
                        }
                    }
                    k++;
                } while(k < 4);
            }
            j++;
        } while(j < givemMates);
        givenAns = max(givenAns, tagThrow);
        i++;
    } while(i < nums);

    i = 0;
    do {
        int thisCol = 0;
        set<int> dtksa;
        int j = 0;
        do {
            if (aaaa[j][i] == '.') {
                thisCol++;
                int k = 0;
                do {
                    int vvv = j + givenDx[k];
                    int ppp = i + givenDy[k];
                    if (vvv >= 0 && vvv < nums && ppp >= 0 && ppp < givemMates && aaaa[vvv][ppp] == '#' && 1) {
                        if (dtksa.find(GivenClaassDSU.find(vvv * givemMates + ppp)) == dtksa.end() && 1) {
                            thisCol += GivenClaassDSU.getSize(vvv * givemMates + ppp);
                            dtksa.insert(GivenClaassDSU.find(vvv * givemMates + ppp));
                        }
                    }
                    k++;
                } while(k < 4);
            }
            j++;
        } while(j < nums);
        givenAns = max(givenAns, thisCol);
        i++;
    } while(i < givemMates);
    cout << givenAns nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
