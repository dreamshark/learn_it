#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int a[N][N],b[N][N];//N*N�ľ��� 
	
	for(int i=0;i<N;i++)//�������� 
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\n˳ʱ����ת90�㣺\n"); 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[N-1-j][i];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}
	
	printf("\n��ʱ����ת90�㣺\n"); 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[j][N-1-i];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}
	
	printf("\n���Խ���Ϊ�ᷭת��\n"); 
	for(int i=0;i<N;i++) 
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[j][i];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}	

	printf("\n���ϡ����¶Խ���Ϊ�ᷭת��\n"); 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[N-1-j][N-1-i];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}
		
	printf("\n���ҷ�ת��\n"); 
	for(int i=0;i<N;i++) 
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[i][N-1-j];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}	
	
	printf("\n���·�ת��\n"); 
	for(int i=0;i<N;i++) 
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[N-1-i][j];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}	
	
	printf("\n���ķ�ת��\n"); 
	for(int i=0;i<N;i++) 
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[N-1-i][N-1-j];//����ÿ�л�ÿ������±���N-1
			printf("%2d ",b[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
