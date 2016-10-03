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
int power[30];
void powfunc(){
    int i;
    power[0]=1;
    for(i=1;i<30;i++)
        power[i]=power[i-1]*2;
}
int main()
{
    int t=getInt();
    powfunc();
    while(t--){
        char arr[31];
        int s=1;
        scanf("%s", arr);
        int temp=1;
        for(int i=1; arr[i]!='\0'; i++){
            if(arr[i]==arr[i-1]){
               temp+=1;
            }
            else{
                s*=power[temp-1];
                temp=1;
            }
        }
        s*=power[temp-1];
        printf("%d\n", s);
    }
}
