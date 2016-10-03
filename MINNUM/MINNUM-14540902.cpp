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
    char n[33];
    scanf("%s", &n);
    while(n[0]!='-'){
        int l=strlen(n);
        int a[l], r=0;
        if(l==1){
            if(n[0]=='0')
                printf("%d\n", 0);
            else
                printf("%d\n", 1);
        }
        else{
            for(int i=0; n[i]!='\0'; i++){
                a[i]=(int)((r*10+(n[i]-'0'))/9);
                r=((r*10+(n[i]-'0'))%9);
            }
            if(r!=0){
            a[l-1]+=1;
            int c=a[l-1]/10;
            a[l-1]=a[l-1]%10;
            if(c>0){
                for(int i=l-2; i>=0; i--){
                    a[i]+=c;
                    c=a[i]/10;
                    a[i]=a[i]%10;
                    if(c==0)
                        break;
                }
            }
            }
            int i=0;
            if(a[i]==0)
                i+=1;
            for(; i<l; i++){
                printf("%d" ,a[i]);
            }
            putchar('\n');
        }
        scanf("%s", &n);
    }
    return 0;
}
