#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
    for(int j=2;j*j<=n;j++) {
        if(n%j==0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n,m,l;
    cin>>n>>m>>l;
    
    vector<pair<int,int> > arr;
    for(int i=0;i<n;i++) {
        int u,v;
        cin>>u>>v;
        arr.push_back({u,v});
    }
    
    vector<pair<int,int> > p;
    
   for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        p.push_back({u,v});
    }
   
   multiset<int> s;
   int ans=0;
   int pos=0;
   int curr =1;
   for(int i=0;i<n;i++) {
       if(arr[i].first<=l && arr[i].second>=l) {
           cout<<-1<<endl;
           return;
       }
         if(arr[i].first>l) {
           cout<<ans<<endl;
           return;
       }
       while(pos<m&&p[pos].first<=arr[i].first) {
           s.insert(p[pos].second);
           pos+=1;
       }
       int diff = arr[i].second - arr[i].first + 1;
       if(curr > diff);
       else {
           while(s.size()) {
                multiset<int>::iterator it = --(s.end());
                curr += *it;
                s.erase(it);
                ans+=1;
                if(curr>diff) {
                    break;
                }
           }
           if(curr<=diff) {
               cout<<-1<<endl;
               return;
           }
          
       }
     
   }
   cout<<ans<<endl;
  
  
  

  
  
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}