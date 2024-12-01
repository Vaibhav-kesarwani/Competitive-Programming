#include<bits/stdc++.h>
using namespace std;

vector<int> make_all_zero(string s){
    int n = s.size() ;
   
    vector<int> t;
    for(int i = 0 ; i < n- 1; i ++){
        if(s[i] != s[i+1]){
            t.emplace_back(i+1) ;
        }
    }
    if(s[n-1] == '1'){
        t.emplace_back(n) ;
    }

    return t;
}

void solve(){
    int n ; cin >> n ;
    string a , b ;
    cin >> a >> b ;

    int op = 0 ;

    vector<int> step1 = make_all_zero(a) ;
    vector<int> step2 = make_all_zero(b) ;

    reverse(step2.begin() , step2.end()) ;

    cout << step1.size() + step2.size() << " " ;
    for(auto x : step1){
        cout << x << " " ;
    }
    for(auto x : step2){
        cout << x << " " ;
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcase ;
    cin >> testcase ;
    for(int i = 0 ; i < testcase ; i ++){
        solve();
    }

    return 0 ;
}