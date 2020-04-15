
#include <stdio.h>		
#include <math.h>	

int isPrime(int n){
    if(n<=3 && n>1)		return 1;				//ȷ�������� 
    if(n%6!=1 && n%6!=5)	return 0;   		//����6�ı������ߵĶ��������� 
    int s = (int)sqrt(n);
    for(int i=5; i<=s; i+=6)
	{
        if(n%i==0 || n%(i+2)==0)				//Ϊ�˱�֤�ٶ���󻯣�ѡȡ6�ı������ߵ��������к��� 
            return 0;							//�ܱ�6�ı������ߵ��������������Բ������� 
    }
    return 1;									//����Ķ������� 
}
int main()
{
	int n;										//�������ݱ�֤n����1 
	while((scanf("%d",&n))!=EOF)
	{
		if((isPrime(n))==1)   printf("������\n");
		else   printf("��������\n"); 
	}
	return 0;
}
