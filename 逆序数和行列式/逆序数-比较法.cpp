#include<stdio.h>
void compare(int digit[],int n);

int cnt=0;//���ڸ����������� 

int main()
{
	int n;
	printf("���ĸ�����"); 
	scanf("%d",&n);
	int digit[n];
	
	printf("����"); 
	for(int i=0;i<n;i++) scanf("%d",&digit[i]);
	
	compare(digit,n);
	printf("��������%d",cnt);
} 


void compare(int digit[],int n)
{
	for(int i=0;i<n;i++)//i�ǵ�ǰ������λ�� 
	{
		for(int j=0;j<i;j++)//j�ǵ�ǰ����ǰ�������λ�� 
		{
			if(digit[j]>digit[i]) cnt++;
		}
	}
}
