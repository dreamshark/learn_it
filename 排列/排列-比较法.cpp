#include<stdio.h>
void arrange(int,int,int []);//Ӧ���ڳ���λ֮�����λ�����к��� 

const int n=4;//n��ѡ���������е����ĸ���
const int number[n]={1,2,3,4};//����������е���

int cnt=0;//cnt���ڼ������ж����ֵ����з�ʽ 

int main()
{
	int m,pos=1;
	printf("λ����");
	scanf("%d",&m);
	int digit[m];//digit���ڴ�ÿ����λ����
		
	for(int i=0;i<n;i++)
	{
		digit[0]=number[i];//��λ���� 
		if(m==1)
		{
			printf("%d\n",digit[0]);
		}
		else
		{
			arrange(m,pos,digit);
		}
	}
	printf("����%d�ֵ����з�ʽ",cnt);
	return 0;
}

//Ӧ����ĳ����λ����ȥ��βλ�������к���
//posΪ��ǰ�������е���λλ�� 
void arrange(int m,int pos,int digit[])
{
	
	for(int i=0;i<n;i++)
	{
		digit[pos]=number[i];
		for(int j=0;j<pos;j++)//j�ǵ�ǰλǰ���λ
		{
			if(digit[j]==digit[pos])//�˴�����λһһ�Ƚϣ����ĳ���Ƿ��ù�
			{
				i++;
				digit[pos]=number[i];
				j=-1;//ÿ������ĳ���ù��󣬾���ͷ��ʼ��� 
				if(i==n) 
					return;
			}
		}
		if(pos==m-1)
		{
			cnt++;
			for(int i=0;i<m;i++)//��� 
			printf("%d",digit[i]);
			printf("\n");
		}
		else
			arrange(m,pos+1,digit);
	}
	return;
}
