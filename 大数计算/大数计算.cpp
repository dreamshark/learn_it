#include<stdio.h>
#include<string.h>
int bigcompare(int [],int [],int);
void bigadd(int [],int [],int);
void bigsubtract(int [],int [],int);
void bigmultiply(int [],int [],int,int);
void bigdivide(int [],int [],int,int);
int main()
{
	char a_char[1000]={0},b_char[1000]={0};//a_char,b_char��ʾ���ַ����鴢��Ĵ��� 
	int a_int[1000],b_int[1000];//a_int,b_int��ʾ���������鴢��Ĵ���
	int len1,len2,ml;
	
	scanf("%s",a_char);//�ֱ��������a,b 
	scanf("%s",b_char);
	len1=strlen(a_char);//len1��len2�ֱ��ʾ����a,b��λ�� 
	len2=strlen(b_char);	
	ml=len1>len2?len1:len2;//mlΪlen1��len2�нϴ��λ�� 
		
	//�ٽ��ַ�����ת��Ϊ���α��������򴢴��������У����ں������� 
	//�ڲ��ڽ�С����ǰ�棨������棩����0ֱ��������λ��ȣ����ں������� 
	for(int i=0,k1,k2;i<ml;i++) 
	{
		k1=len1-1-i;
		k2=len2-1-i;
		
		if(k1>=0) a_int[i]=a_char[k1]-'0';
		else a_int[i]=0;	
		if(k2>=0) b_int[i]=b_char[k2]-'0';
		else b_int[i]=0;
	}
	
	printf("��С�Ƚϣ�%d\n",bigcompare(a_int,b_int,ml)) ;
	printf("�ͣ�");
	bigadd(a_int,b_int,ml);
	printf("�");
	bigsubtract(a_int,b_int,ml);
	printf("����");
	bigmultiply(a_int,b_int,len1,len2); 
	printf("�̣�");
	bigdivide(a_int,b_int,len1,len2); 	
	return 0;
} 
 
int bigcompare(int a_int[],int b_int[],int ml)//����a_int,b_int��С�ȽϽ�� 
{
	for(int i=ml-1;i>=0;i--)//a_int����b_int����1�����ڷ���0��С�ڷ���-1
	{
		if(a_int[i]>b_int[i]) return 1;
		else if(a_int[i]<b_int[i]) return -1;
		else if(i==0) return 0;
	}
}

void bigadd(int a_int[],int b_int[],int ml)
{
	int t,carry=0;//tΪ��������е���ʱֵ��carry��ʾ��λ 
	char ans[ml+2];
	ans[ml]='\0';//������2��Ԫ�ظ�ֵΪ���ַ� 
	
	for(int i=0;i<ml;i++)
	{
		t=a_int[i]+b_int[i]+carry;
		if(t<10) 
		{
			ans[ml-1-i]=t+'0';
			carry=0;
		}
		else
		{
			ans[ml-1-i]=t%10+'0';
			carry=t/10;
		}
	}
	
	//�����λ�н�λ�����ַ�����Ԫ���������1����λ��������ǰ����Ͻ�λ 
	if(carry!=0)
	{
		for(int i=ml+1;i>=1;i--)
		{
			ans[i]=ans[i-1];
		}
		ans[0]=carry+'0';
	}
	puts(ans);
	return;	
}

void bigsubtract(int a_int[],int b_int[],int ml)
{
	int t,borrow=0,flag;//tΪ��������е���ʱֵ��borrow��ʾ��λ
	int *max,*min;
	char ans[ml+2];
	ans[ml]='\0';//������2��Ԫ�ظ�ֵΪ���ַ� 
	
	flag=bigcompare(a_int,b_int,ml);//flag��ʾ������С�ȽϵĽ�� 
	if(flag==0)
	{
		ans[0]='0';
		ans[1]='\0';
		puts(ans);
		return;
	}
	else if(flag==1)//���ҳ��ϴ����������ýϴ������ȥ��С���������������ȷ��
	{
		max=a_int;
		min=b_int;
	}
	else if(flag==-1)
	{
		max=b_int;
		min=a_int;
	}
	
	
	for(int i=0;i<ml;i++)//�ϴ������ȥ��С����
	{
		t=max[i]-min[i]-borrow;
		if(t>=0) 
		{
			ans[ml-1-i]=t+'0';
			borrow=0;
		}
		else
		{
			ans[ml-1-i]=t+10+'0';
			borrow=1;
		}
	}
	
	int i,j;//�൱��ȥ������ǰ������0
	for(i=0;i<ml&&ans[i]=='0';i++);
	for(j=0;i<ml;i++,j++)
	{
		ans[j]=ans[i];
	}
	ans[j]='\0';

	//�����Ϊ���������ַ�����Ԫ���������һ����λ��������ǰ����ϸ���
	if(flag==-1)
	{
		for(int i=ml+1;i>=1;i--)
		{
			ans[i]=ans[i-1];
		}
		ans[0]='-';
	}
	
	puts(ans); 
	return;
}

void bigmultiply(int a_int[],int b_int[],int len1,int len2)
{
	int sl=len1+len2;//slΪ����������λ���� 
	int digit[sl]={0},t;//�Ȳ������λ��digit���ڴ��水λ�˷������ó��ĸ���λ����
	int ans_int[sl];
	char ans_char[sl];
	
	for(int i=0;i<len1;i++)//��λ���г˷����� 
	{
		for(int j=0;j<len2;j++)
		{
	 		t=a_int[i]*b_int[j];
	 		digit[i+j]+=t;
		}
	}

	for(int i=0;i<sl;i++)//������λ 
	{
		if(digit[i]<10) ans_int[i]=digit[i];
		else
		{
			ans_int[i]=digit[i]%10;
			digit[i+1]+=digit[i]/10;
		}
		 
	}
	
	int i,j;
	for(i=sl-1;i>=1&&ans_int[i]==0;i--);//�൱��ȥ������ǰ���ڵ�0�������������͵Ļ�ת��Ϊ�ַ����� 
	for(j=0;i>=0;i--,j++)
	{
		ans_char[j]=ans_int[i]+'0';
	}
	ans_char[j]='\0';
	puts(ans_char);
	return;
}

void bigdivide(int a_int[],int b_int[],int len1,int len2)
{
	int ml=len1>len2?len1:len2;//mlΪlen1��len2�нϴ��λ��  
	int dl=len1-len2;//dlΪ����������λ����
	int t,borrow=0;//tΪ��������е���ʱֵ��borrowΪ���ô�������ʱ�Ľ�λ
	int pos=dl;//pos��ʾԭ��b_int�ĸ�λ����b_t�����е�λ�ã�Ҳ����b_tΪԭ��b_int��10^pos�� 
	int a_t[10000],b_t[10000];//a_t��b_t�ֱ��ʾa_int�������b_int�Ŵ�����ʱ��
	int ans_int[ml]={0};
	char ans_char[ml];

	if(len2==1&&b_int[0]==0)//��b_intΪ0������������ 
	{
		printf("error");
		return;
	}
	
	if(bigcompare(a_int,b_int,ml)<0)//��a_intС��b_int����Ϊ0 
	{
		ans_char[0]='0';
		ans_char[1]='\0';
		puts(ans_char);
		return;
	}
	
	//a_int���Ƹ�a_t
	for(int i=0;i<len1;i++)
		a_t[i]=a_int[i]; 
	
	//b_tΪԭ��b_int��10^dl��
	for(int i=0;i<dl;i++)
		b_t[i]=0;	
	for(int i=dl,j=0;i<ml;i++,j++)
		b_t[i]=b_int[j];
		
	//��a_tС�ڷŴ���b_t����b_t����ǰ�ƣ�Ҳ������С10������������ǰ������󣩲�0 	
	if(bigcompare(a_t,b_t,ml)==-1&&pos>=1)
	{
		for(int i=0;i<ml-1;i++)
			b_t[i]=b_t[i+1];
		b_t[ml-1]=0;
		pos--;
	}
			
	while(bigcompare(a_t,b_t,ml)>=0)
	{
		while(bigcompare(a_t,b_t,ml)>=0)
		{
			for(int i=0;i<ml;i++)//a_t��ȥb_t 
			{
				t=a_t[i]-b_t[i]-borrow;
				if(t>=0) 
				{
					a_t[i]=t;
					borrow=0;
				}
				else
				{
					a_t[i]=t+10;
					borrow=1;
				}
			} 
			ans_int[pos]++;//��¼�� 
		}
	
		//ֻҪb_t��a_t�������b_t�ͻ᲻ͣ��С10��ֱ��С��a_t����������С��С��ԭ��b_int
		while(pos>=1&&bigcompare(a_t,b_t,ml)==-1)
		{
			for(int i=0;i<ml-1;i++)
			b_t[i]=b_t[i+1];
			b_t[ml-1]=0;
			pos--;
		}
	}

	int i,j; 
	for(i=dl;i>=0&&ans_int[i]==0;i--);//�൱��ȥ������ǰ���ڵ�0�������������͵���ת��Ϊ�ַ�����  
	for(j=0;i>=0;i--,j++)
	{
		ans_char[j]=ans_int[i]+'0';
	}
	ans_char[j]='\0';
	puts(ans_char);
	return;
}
