#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n,i,flag=1;
	scanf("%d",&n);
	if(n==1) printf("��������");
	else if(n==2) printf("������");
	else if(n==3) printf("������");
	else
	{
		for(i=2;i<=sqrt(n);i++)//��һ�����ſ��Դﵽ������ж�Ч�� 
		{
			if(n%i==0)
			{
				printf("��������");
				flag=0;
				break;
			}
		}
		if(flag) printf("������");
	}
	return 0;
}
