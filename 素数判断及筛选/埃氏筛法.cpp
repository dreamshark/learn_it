
#include<stdio.h>		 
#include<string.h>	
#define LENGTH 10000				//���10000���Լ���Ҫ����һ���ķ�Χ�ڵ�������Ҫ�������� 
int main(){
    int n,p=0,i; 
    int bad_boy[LENGTH];				//Ҫ�жϵ����� 
	int good_boy[LENGTH];				//ȷ�������������� 
    memset(bad_boy,0,sizeof(int)*LENGTH);		//���������㣬ͷ�ļ��� <string.h>
    for(i=2;i<=100;i++)						//100����10000���ĸ��ŵ�ֵ 
	{										
        if(bad_boy[i]==0)
		{
            good_boy[p++]=i;						//����һ�������������װ���� 
            for(int j=2*i;j<=10000;j+=i)		//�ų�1000000�ķ�Χ�����������Ѿ�ȷ���������ı��� 
                bad_boy[j]=1;					//ֱ�������ǵ���1���Ϳ��Ա����������Ϊ0���ж������� 
        }
    }
    for(;i<=10000;i++)					//����������δ�����ж�����Ҫ�Ѹ�����������ж��� 
        if(bad_boy[i]==0)
            good_boy[p++]=i;
        for(int i=0;i<p;i++)			//���10000��Χ�ڵ���������
        {
        	printf("%d ",good_boy[i]);
		}
        printf("\n");
    return 0;
} 
