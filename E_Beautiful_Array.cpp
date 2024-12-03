#include<bits/stdc++.h>
using namespace std;



int main()
{
    int a,b;
    cin>>a>>b;
    vector<int> w({-1000,b,1000});
    int x=3*a-b;
    if(x>=0)
        w[2]+=x;
    else
        w[0]+=x;
    cout<<3<<"\n";
    for(int i=0;i<3;i++)
        cout<<w[i]<<" \n"[i+1==3];
}