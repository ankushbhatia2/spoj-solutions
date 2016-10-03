#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p,m;
        scanf("%d%d",&p,&m);
        int arr[p+9],flag=0;
        long long sum=0,max=-1,total=99999999,cumu[p+9];
        cumu[0]=0;
        for(int i=1;i<=p;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
            cumu[i] =sum;
        }
        int p1=0,p2=0;
        sum=0;
        for(int i=1;i<=p;i++)
        {
            if(flag==1)
                i--;
            sum= cumu[i] - cumu[p1];
            flag=0;
            if(sum>m)
            {
                flag=1;
                p1++;
            }
            if(max<(i-p1)){
                max=(i-p1);
                total = sum;
            }
            else if(max==(i-p1))
            {
                if(total>sum)
                    total=sum;
            }
        }
        if(max==0)
            total=0;
        if(total==99999999)
            printf("0 0\n");
        else
            printf("%lld %lld\n",total,max);
    }
    return 0;
}