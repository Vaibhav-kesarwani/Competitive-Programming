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
const int mod=998244353,MAX=100005,INF=15<<26;

vector<set<int>> X[MAX];
int syu[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N;cin>>N;
        int Q;cin>>Q;
        vi A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vii que(Q);
        for(int i=0;i<Q;i++){
            int a,b;cin>>a>>b;a--;
            que[i]=mp(a,b);
        }
        vi svA=A;
        vi ans(Q);
        for(int K=1;K<=N;K*=2){
            A=svA;
            set<pii> SE;
            int i=0;
            while(i<N){
                if(A[i]>=K){
                    i++;
                    continue;
                }
                int j=i;
                while(j<N&&A[j]<K) j++;
                SE.insert(mp(i,j));
                i=j;
            }
            for(int i=0;i<N;i++){
                X[i].clear();
                syu[i]=0;
            }
            multiset<int> OK;
            
            for(auto [l,r]:SE){
                if(r-l>=K){
                    X[l].resize(K);
                    for(int i=l;i<r;i++){
                        X[l][A[i]].insert(i);
                        if(si(X[l][A[i]])==1) syu[l]++;
                    }
                    if(syu[l]==K) OK.insert(r-l);
                }
            }
            
            for(int q=0;q<Q;q++){
                auto [i,x]=que[q];
                if(A[i]<K){
                    auto it=SE.lower_bound(mp(i,INF));it--;
                    auto [l,r]=*it;
                    if(si(X[l])){
                        if(si(X[l][A[i]])==1){
                            if(syu[l]==K) OK.erase(OK.find(r-l));
                            syu[l]--;
                        }
                        X[l][A[i]].erase(i);
                        
                        A[i]+=x;
                        chmin(A[i],K+K);
                        
                        if(A[i]>=K){
                            if(i==l){
                                SE.erase(mp(l,r));
                                if(syu[l]==K) OK.erase(OK.find(r-l));
                                swap(X[l],X[l+1]);
                                swap(syu[l],syu[l+1]);
                                SE.insert(mp(l+1,r));
                                if(syu[l+1]==K) OK.insert(r-l-1);
                            }else if(i==r-1){
                                SE.erase(mp(l,r));
                                if(syu[l]==K) OK.erase(OK.find(r-l));
                                SE.insert(mp(l,r-1));
                                if(syu[l]==K) OK.insert(r-l-1);
                            }else{
                                int a,b,c,d;
                                a=l;b=i;c=i+1;d=r;
                                
                                SE.erase(mp(l,r));
                                if(syu[l]==K) OK.erase(OK.find(r-l));
                                
                                
                                if(b-a<d-c){
                                    swap(X[l],X[c]);
                                    swap(syu[l],syu[c]);
                                    
                                    if(b-a>=K) X[l].resize(K);
                                    
                                    for(int j=a;j<b;j++){
                                        if(si(X[c][A[j]])==1){
                                            syu[c]--;
                                        }
                                        X[c][A[j]].erase(j);
                                        
                                        if(si(X[l])){
                                            X[l][A[j]].insert(j);
                                            if(si(X[l][A[j]])==1) syu[l]++;
                                        }
                                    }
                                    
                                    if(b-a<K){
                                        X[l].clear();
                                        syu[l]=0;
                                    }else{
                                        if(syu[l]==K) OK.insert(b-a);
                                    }
                                    SE.insert(mp(a,b));
                                    
                                    if(d-c<K){
                                        X[c].clear();
                                        syu[c]=0;
                                    }else{
                                        if(syu[c]==K) OK.insert(d-c);
                                    }
                                    SE.insert(mp(c,d));
                                }else{
                                    if(d-c>=K) X[c].resize(K);
                                    
                                    for(int j=c;j<d;j++){
                                        if(si(X[l][A[j]])==1){
                                            syu[l]--;
                                        }
                                        X[l][A[j]].erase(j);
                                        
                                        if(si(X[c])){
                                            X[c][A[j]].insert(j);
                                            if(si(X[c][A[j]])==1) syu[c]++;
                                        }
                                    }
                                    
                                    if(b-a<K){
                                        X[l].clear();
                                        syu[l]=0;
                                    }else{
                                        if(syu[l]==K) OK.insert(b-a);
                                    }
                                    SE.insert(mp(a,b));
                                    
                                    if(d-c<K){
                                        X[c].clear();
                                        syu[c]=0;
                                    }else{
                                        if(syu[c]==K) OK.insert(d-c);
                                    }
                                    SE.insert(mp(c,d));
                                }
                                
                            }
                        }else{
                            X[l][A[i]].insert(i);
                            if(si(X[l][A[i]])==1){
                                syu[l]++;
                                if(syu[l]==K) OK.insert(r-l);
                            }
                        }
                    }
                }
                
                if(si(OK)) chmax(ans[q],*OK.rbegin());
            }
        }
        
        for(int q=0;q<Q;q++) cout<<ans[q]<<"\n";
    }
}


