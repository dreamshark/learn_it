#include<stdio.h>

const int n=4;//n��ѡ���������е����ĸ���
const int number[n]={1,2,3,4};//����������е���
int digit[n];//ȫ���е���λ�������������е����ĸ������

int cnt=0;

void swap(int *,int*);
void arrange(int,int);

int main()
{
	for(int i=0;i<n;i++)
		digit[i]=number[i];
	arrange(n,0);
	printf("����%d������",cnt);
	return 0;
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void arrange(int n,int pos)
{
	if(pos==n-1)//�����һλʱ 
	{
		cnt++;
		for(int i=0;i<n;i++)
			printf("%d",digit[i]);
		printf("\n");
	}
	else
	{
		for(int i=pos;i<n;i++)//i�ǵ�ǰλpos�����λ 
		{
			swap(digit+i,digit+pos);//digit[i]��digit[pos]���� 
			arrange(n,pos+1);//���뵽��һλ������ 
			swap(digit+i,digit+pos);//��ԭ���������� 
		}
	}
}



