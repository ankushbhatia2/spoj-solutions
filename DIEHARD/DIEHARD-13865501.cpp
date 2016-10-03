#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1001][1200],i,j,t;
int rec(int n,int m)
{
	if(n<=0||m<=0)
	return -1;
	else
	{
	if(a[n][m]==-1)
	a[n][m]=max(rec(n-2,m-8)+2,rec(n-17,m+7)+2);
    return a[n][m];
}
}
int main() 
{
	int n,m;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d %d",&n,&m);
	for(i=n;i>0;i--)
	{
		for(j=m+100;j>0;j--)
		a[i][j]=-1;
	}
	printf("\n%d",rec(n,m));
	}
	return 0;
}