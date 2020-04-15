#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n,i,flag=1;
	scanf("%d",&n);
	if(n==1) printf("不是素数");
	else if(n==2) printf("是素数");
	else if(n==3) printf("是素数");
	else
	{
		for(i=2;i<=sqrt(n);i++)//开一个根号可以达到更快的判断效果 
		{
			if(n%i==0)
			{
				printf("不是素数");
				flag=0;
				break;
			}
		}
		if(flag) printf("是素数");
	}
	return 0;
}
