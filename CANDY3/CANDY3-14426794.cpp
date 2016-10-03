#include <bits/stdc++.h>
using namespace std;
#define Get getchar()
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long s=0;
        cin>>n;
        for(int i=0; i<n; i++){
            long long a;
            cin>>a;
            s = s+a;
            if(s>=n)
               s = s%n; 
        }
        if(s==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
