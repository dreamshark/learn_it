#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n==1) printf("��������");
	else if(n==2) printf("������");
	else
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{
				printf("��������");
				break;
			}
			else if(n%i!=0 && i==n-1)
			{
				printf("������");
			}
		}
	}
	return 0;
}

