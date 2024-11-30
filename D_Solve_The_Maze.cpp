#include<bits/stdc++.h>
//#define in freopen ("input.txt", "r", stdin);
//#define out freopen("output.txt", "w", stdout);
#define ll long long
#define FILE1
#define yes cout<<"YES\n";
#define no cout<< "NO\n";
const int  val = 60;
const long long mod=1e9+7;
ll binpow(ll x , ll n){
    ll ans = 1;
    while(n > 0){
        if(n % 2){
            n--;
            ans = ans * x % mod;
        }else {
        n /= 2;
        x = x * x % mod;
        }
    }
    return ans;
}
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
map<pair<int,int>,bool> used;
char ar[val][val];
int ans[val][val];
int cnt1=0;
void dfs(int i , int j , int n , int m){
	used[{i,j}]=true;
	if(i==n-1 and j==m-1){
		ans[i][j]=1;
	}
	if(ar[i-1][j]!='#' and i-1>=0 and  used[{i-1,j}]==0){
		dfs(i-1,j,n,m);
	}
	if(ar[i+1][j]!='#' and i+1<n and  used[{i+1,j}]==0){
		dfs(i+1,j,n,m);
	}
	if(ar[i][j-1]!='#' and j-1>=0 and  used[{i,j-1}]==0){
		dfs(i,j-1,n,m);
	}
	if(ar[i][j+1]!='#' and j+1<m and  used[{i,j+1}]==0){
		dfs(i,j+1,n,m);
	}

}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			ar[i][j]='!';
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char a;
			cin>>a;
			ar[i][j]=a;
			if(a=='G'){
				cnt++;
			}
		}
	}
	
	//cout<< "bromad\n";
	int cnt1=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ar[i][j]=='B'){
				cnt1++;
				if(ar[i+1][j]=='G' || ar[i-1][j]=='G' || ar[i][j-1]=='G' || ar[i][j+1]=='G'){
					cout<< "No\n";
					return;
				}
				if(ar[i+1][j]=='.' and i+1<n){
					ar[i+1][j]='#';
				}
				if(ar[i-1][j]=='.' and i-1>=0){
					ar[i-1][j]='#';
				}
				if(ar[i][j-1]=='.' and j-1>=0){
					ar[i][j-1]='#';
				}
				if(ar[i][j+1]=='.' and j+1<m){
					ar[i][j+1]='#';
				}
			}
		}
	}
	used.clear();
	if(ar[n-1][m-1]=='.'){
		dfs(n-1,m-1,n,m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((ar[i][j]=='G' and used[{i,j}]==0) || (ar[i][j]=='B' and used[{i,j}]==1)){
				cout<< "No\n";
				//cout<< i << " " << j << " " << used[{i,j}] << endl;
				return;
			}
		}
	}
	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			ans[i][j]=0;
		}
	}
	cout<< "Yes\n";
}
int main ()
{
	
 
 
	#ifdef FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
    ios::sync_with_stdio(0);
    //cin.tie(0);
    long long t;
	cin>>t;
    while(t--){
        solve ();
    }
}