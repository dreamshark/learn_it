#include<iostream>
using namespace std;

void mergesort(int temp_digit[],int L,int R);

int cnt=0;//���ڸ����������� 

int main()
{
	int n;
	cout<<"��������ĸ�����";
	cin>>n;
	int temp_digit[n];
	cout<<"׼�����������";
	for(int i=0;i<n;i++) cin>>temp_digit[i];
	mergesort(temp_digit,0,n-1);
	cout<<"�������������";
	for(int i=0;i<n;i++) cout<<temp_digit[i]<<" ";
	cout<<endl<<"��������"<<cnt; 
} 


void mergesort(int temp_digit[],int L,int R)//L,R�ֱ�Ϊ��ǰ�������βλ�� 
{
	if(L==R) return;//������ֻʣһ�������޷��ٷָ�ʱ�������� 
	int middle=(L+R)/2;//����ǰ����һ��Ϊ��
	mergesort(temp_digit,L,middle);//��������ͬ��һ��Ϊ����ֱ�������޷��ٷָ� 
	mergesort(temp_digit,middle+1,R);
	int temp[R-L+1];
	//��ʱ���飬������ʱ����ź������
	//�ﵽ���򲢺ϲ����������Ч�� 
	int pos1=L,pos2=middle+1,pos3=0;
	//pos1����������1�еĵ�ǰλ��
	//pos2����������2�еĵ�ǰλ��
	//pos3������ʱ�����еĵ�ǰλ�� 
	while(pos1<=middle&&pos2<=R)
	{
		//���������е������бȽϣ���С����������ʱ����ǰ�� 
		if(temp_digit[pos1]<=temp_digit[pos2]) 
		{
			temp[pos3++]=temp_digit[pos1++];
		}
		else
		{
			temp[pos3++]=temp_digit[pos2++];
			cnt+=middle-pos1+1;
			 //��������2��ǰλ�õ�����������1��ǰλ�õ���Сʱ�������е��ڣ�
			 //������1��ʣ������ĸ������������������� 
		}
	} 
	while(pos1<=middle)//���ȽϺ�������1ʣ������Ž���ʱ���� 
	{
		temp[pos3++]=temp_digit[pos1++];
	}	
	while(pos2<=R)//���ȽϺ�������2ʣ������Ž���ʱ���� 
	{
		temp[pos3++]=temp_digit[pos2++];
	}

	for(int i=0;i<pos3;i++)//����ʱ�����ź�������Ż�ԭ����
	{
		temp_digit[L+i]=temp[i];
	}
}
