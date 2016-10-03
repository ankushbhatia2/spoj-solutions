#include<bits/stdc++.h>
#define Get getchar()
#define ll unsigned long long
#define pc(x) putchar(x)
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



int main()
{
    //SieveOfEratosthenes(100001);
    int t=getInt();
    while(t--){
        int n=getInt();
        int a[n];
        bool b=true;
        for(int i=0; i<n; i++){
            a[i]=getInt();
        }
        sort(a, a+n);
        ll ans=1;
        for(int i=n-1; i>=0; i--){
            if(a[i]-i<=0){
                b=false;
                break;
            }
            ans*=(a[i]-i);
            ans=ans%1000000007;
        }
        if(b==false)
            printf("0\n");
        else
            printf("%llu\n", ans);
    }
    printf("KILL BATMAN\n");
    return 0;
}
