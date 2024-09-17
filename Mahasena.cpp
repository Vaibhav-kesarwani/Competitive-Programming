#include <iostream>

using namespace std;



int main() {

	int n; // no. of soldiers

	cin>>n;

	int a[n];

	int lucky=0,unlucky=0;

	for(int i=0;i<n;i++){  

	    //store no. of weapons by particular soldier in an array

	    cin>>a[n];

	}

	

	for(int i=0;i<n;i++)

	{

	    if(a[n]%2==0)  //condition for checking whether no. of weapons even or not

	        lucky++; // if satisfies increase lucky count by one

	    else

	        unlucky++; //else increase unlucky

	}

	

	if(lucky>unlucky)

	    cout<<"READY FOR BATTLE"<<endl;   //display as per the required output

	else

	    cout<<"NOT READY"<<endl;

	return 0;

}