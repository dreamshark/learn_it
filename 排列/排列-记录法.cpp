#include<stdio.h>
void arrange(int,int,int [],struct FLAG);//Ӧ����ĳ����λ�����к���
struct FLAG copy(struct FLAG);

const int n=4;//n��ѡ���������е����ĸ���
const int number[n]={1,2,3,4};//����������е���
//��number������������ּ��ɴﵽ��������������з�ʽ��Ч��
int cnt=0;//cnt���ڼ������ж����ֵ����з�ʽ 

/*array���ڼ�¼ĳλ�������Ƿ��б��ù� 
��iλ��ֵ�����������е�����number[i]��ʹ�������0Ϊδʹ�ù���1Ϊʹ�ù�*/
/*��������ڽṹ����Ϊ��ÿ�����ڵ�ǰ��λ�����к�����
������ĸ������ݵ���һ����λ�����к���,�����Ǵ���ָ�� */
struct FLAG
{
	int array[n]; 
};
int main()
{
	int m,pos=0; 
	struct FLAG flag;
	
	for(int i=0;i<n;i++)
		flag.array[i]=0;//�൱�ڸ�flag������ȫ����ʼ��Ϊ0
		
	printf("λ����");
	scanf("%d",&m);//m����λ�ĸ������൱�ڴ�n������m����������
	
	int digit[m];//digit���ڴ�ÿ����λ���� 
	
	arrange(m,pos,digit,flag);//����m����λ����n�������е�����
	//�൱�ڴ�n������ѡ��m�����е����� 
	
	printf("����%d�����з�ʽ",cnt);
	return 0;
}

//Ӧ����ĳ����λ�����к���
//posΪ��ǰ�������е���λλ�� 
void arrange(int m,int pos,int digit[],struct FLAG flag)
{
	int i;
	if(pos==m)//�����һλ��������� 
	{
		cnt++;
		for(int i=0;i<m;i++) printf("%d",digit[i]);
		printf("\n");
		return;
	}
	if(pos==0&&number[0]==0) i=1;//��λ����Ϊ0 
	else i=0;
	for(;i<n;i++)
	{
		if(flag.array[i]) continue;//��ĳ�����ֱ�ʹ�ù�����ֱ������������ 
		digit[pos]=number[i];
		flag.array[i]=1;//��¼ĳ���ֱ�ʹ�ù� 
		arrange(m,pos+1,digit,copy(flag));
		flag.array[i]=0;//��ԭĳ����ʹ����� 
	}

}

//����ǰ��¼����ʹ����������鸴�ƣ���������һ����λ�����к��� 
struct FLAG copy(struct FLAG flag)
{
	struct FLAG new_flag;
	new_flag=flag;
	return new_flag;
}
