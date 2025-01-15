#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

int w[25]={2,3,5,7,11,13,17,19,23,29,31,37,43,41,47},k[25]={4,9,25,49};

char s[25];

int main()
{
	int ok=0;
	for(int i=0;i<15;i++)
	{
		printf("%d\n",w[i]);
		fflush(stdout);
		scanf("%s",s);
		ok+=s[0]=='y';
	}
	if(ok>=2)
	{
		printf("composite\n");fflush(stdout);return 0;
	}
	ok=0;
	for(int i=0;i<4;i++)
	{
		printf("%d\n",k[i]);
		fflush(stdout);
		scanf("%s",s);
		ok+=s[0]=='y';
	}
	if(ok)
	{
		printf("composite\n");fflush(stdout);return 0;
	}
	printf("prime\n");fflush(stdout);return 0;
}
