
#include <stdio.h>			
#include <string.h>			 

int main()
{
	int i,j,kwe=0,n;
	int bad_boy[1009];						//Ҫ�ж��Ƿ�Ϊ���������� 
	int good_boy[1009];						//ȷ�������������� 
	scanf("%d",&n);
	memset(bad_boy,0,sizeof(bad_boy));		// ���������㣬ͷ�ļ��� <string.h>									
	for(i=2;i<=n;i++)						
	{
		if(bad_boy[i]==0)					
		{
			good_boy[kwe++]=i;				//����Ԫ��Ϊ�㣬����ʱ������±�������������±������ 
		}
		for(j=0;j<kwe && i*good_boy[j]<=n;j++)		
		{
			bad_boy[i*good_boy[j]]=1;		//�������������������Բ���������������ɸ�� 
			if(i%good_boy[j]==0)  break;	//�˲�����֤��ֻ����С������ɸѡ���Ӷ���֤ɸѡ�����ظ������磬��i=4ʱ�� �����У� 
		}									//i%good_boy[0](Ҳ����2��=0,�����ʱ���˳�ѭ��������ͻ���� �����У�
	}										//i* good_boy[1](Ҳ����3��= 12��Ȼ����������i������6ʱ��ͬ�����Գ��� �����У�
	for(int i=0;i<kwe;i++)					//i* good_boy[0](Ҳ����2��= 12��Ҳ����˵����12ɸѡ�����Ρ�����Ҫ�� i%good_boy[j]=0ʱ�˳�ѭ�� 
    {
       	printf("%d ",good_boy[i]);
	}											
	return 0;
} 

