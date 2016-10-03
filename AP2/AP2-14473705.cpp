#include<bits/stdc++.h>
#define Get getchar()
#define ll unsigned long long
#define pc(x) putchar(x)
inline int getInt()
{
    int a=0,s=1;
    char c=Get;
    while(c<33)
        c=Get;
    if(c=='-')
    {
        s=-1;
        c=Get;
    }
    while(c>33)
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=Get;
    }
    return a*s;
}
int main()
{
	int t=getInt();
	while(t--)
	{
		ll x,y,z,a,d,n,term;
		scanf("%llu%llu%llu",&x,&y,&z);
		n = (2*z)/(x+y);
		d = (y-x)/(n-5);
		a = x-(2*d);
		term = a;
		printf("%lld\n",n);
		for(int i = 0 ; i < n ; i++)
		{
			printf("%llu ",term);
			term += d;
		}
		printf("\n");
	}
	return 0;
}