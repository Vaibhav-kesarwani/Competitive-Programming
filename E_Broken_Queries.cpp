#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvii vector<vector<pair<int,int>>>
#define vvll vector<vector<pair<ll,ll>>>
#define vst vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mkunique(x) sort(all(x));(x).erase(unique(all(x)),(x).end())
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=15<<26;

ll ask(ll x,ll y){
    cout<<"? "<<x+1<<" "<<y<<endl;
    ll z;cin>>z;
    return z;
}

int main(){
    
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        ll x=ask(0,N/2);
        ll l,r;
        if(x==0){
            l=N/2;r=N;
        }else{
            l=0;r=N/2;
        }
        ll y=ask(l,(l+r)/2),z=ask((l+r)/2,r);
        if(y+z==1){
            ll ok=N/2,ng=N;
            while(ng-ok>1){
                ll mid=(ok+ng)/2;
                ll a;
                if(l==N/2) a=ask(N-mid,N);
                else a=ask(0,mid);
                
                if(a==0) ng=mid;
                else ok=mid;
            }
            cout<<"! "<<ng<<endl;
        }else{
            ll ok=1,ng=N/2;
            while(ng-ok>1){
                ll mid=(ok+ng)/2;
                ll a;
                if(l==N/2) a=ask(N-mid,N);
                else a=ask(0,mid);
                
                if(a) ng=mid;
                else ok=mid;
            }
            cout<<"! "<<ng<<endl;
        }
    }
}


