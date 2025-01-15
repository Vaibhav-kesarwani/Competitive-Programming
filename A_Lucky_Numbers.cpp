#include<bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int x=-1,result=-1;
        for(int i=l;i<=r&&i<=l+1000;i++)
        {
            string r=to_string(i);
            sort(r.begin(),r.end());
            if(r.back()-*r.begin()>=x)
            {
                x=r.back()-*r.begin();
                result=i;
            }
        }
        cout<<result<<'\n';
    }
}
