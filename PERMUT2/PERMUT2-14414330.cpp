#include<stdio.h>
int main()
{
	int hash[100005];
	int i,n;
	scanf("%d",&n);
	while(n!=0)
	{
		int arr[n+1];
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			hash[arr[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			if(arr[i]!=hash[i])
				break;
		}
		if(i==n+1)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		scanf("%d",&n);
	}
	return 0;
}
