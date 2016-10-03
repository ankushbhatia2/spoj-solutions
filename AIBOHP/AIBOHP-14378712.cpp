#include<cstdio>
#include<iostream>
#include<cstring>
#define Get getchar()
#define ll unsigned long long
#define pc(x) putchar(x)
#define MAX 100000
static int L[6100][6100];
using namespace std;
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
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
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/* Returns length of LCS for X[0..m
ll fact(int a){
    if(a == 0)
        return 1;
    else{
        ll b=1;
        for(int i=1; i<=a; i++)
            b*=i;
        return b;
    }
}*/
int main()
{
    int t=getInt();
    while(t--){
        char a[MAX];
        scanf("%s", &a);
        int n=strlen(a);
        int i, j;

        for (i=0; i<=n; i++){
            for (j=0; j<=n; j++){
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (a[i-1] == a[n-j])
                    L[i][j] = L[i-1][j-1] + 1;
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        cout<<n-L[n][n]<<endl;
    }
    return 0;
}
