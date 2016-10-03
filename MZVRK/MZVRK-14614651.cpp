#include<bits/stdc++.h>
#define Get getchar()
#define ll unsigned long long
using namespace std;
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
ll a[63];
ll calc(ll x)
{
    ll res = 0, aux = 0;
    while (x) {
        if (x % 2) res += a[aux];
        x >>= 1;
        ++aux;
    }
    return res;
}
int main()
{
    a[0] = 1;
    for (int i = 1; i < 63; ++i) {
        a[i] = 1LL << i;
        for (int j = 0; j < i; ++j)
            a[i] += a[j];
    }
    ll a, b;
    scanf("%llu%llu", &a, &b);
    printf("%llu\n", calc(b) - calc(a-1));
    return 0;
}
