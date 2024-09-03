#include<bits/stdc++.h>


using namespace std;


int prime_checking(int m)

{
    int i,p=0;
    int l=sqrt(m);
    for(i=2;i<=l+1;i++)
    {
        if(m%i==0)
        {
            p=1;
            return 0;
            break;
        }
        else
        {
            p=0;
        }

    }
    if(p==0)
    {
        return 1;
    }

}

int main()
{
    int n,j;
    cin>>n;
    for(j=4;j<=n-1;j+=2)
    {
        if(prime_checking(n-j)==0){
            cout<<j<<" "<<(n-j)<<endl;
            break;
    }
    else{
        continue;
    }

}
return 0;
}