#include<bits/stdc++.h>
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
int calc(int n,int div)
{
    if(div==1)
        return -1;
   if(n%div==0&&n/div>1)
   {
       return div+calc(n/div,div)*10;
   }
   else if(n%div==0&&n/div==1)
   {
       return n;
   }
   else
       return calc(n,div-1);

}
int main()
{
    int t=getInt();
    while(t--){
        int n=getInt();
        if(n==0){
            printf("10\n");
        }
        else{
            n=calc(n,9);
            if(n<0)
                printf("-1\n");
            else
                printf("%d\n", n);
        }
    }
    return 0;
}
