#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n==1) printf("不是素数");
	else if(n==2) printf("是素数");
	else
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{
				printf("不是素数");
				break;
			}
			else if(n%i!=0 && i==n-1)
			{
				printf("是素数");
			}
		}
	}
	return 0;
}

