#include<stdio.h>

void swap(int *,int*);
void arrange(int [],int [],int [],int,int);
void mergesort(int [],int,int);

int cnt=0;//cnt��������������
int term_cnt=0;//term_cnt������������ 
int ans=0;//ansΪ����ʽ������

int main()
{
	int n;
	printf("����ʽ������");
	scanf("%d",&n);
	int digit[n];
	int temp_digit[n];//temp_digit��digit����ʱ���������ڸ��鲢���������������� 
	int det[n*n];
	//Ϊ���㽫���鴫�뺯������һά����det�洢����ʽԪ�� 
	//����ʽ��i��j��Ԫ��Ϊ����det�е�i*n+j��Ԫ�� 
	printf("\n����ʽ��\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&det[i*n+j]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		digit[i-1]=i;
	}

	printf("\n����ʽ����ʽ���\n");
	arrange(det,digit,temp_digit,n,0);
	printf("\n����ʽ����ʽ������%d\n\n",term_cnt);
	printf("����ʽ������Ϊ��%d",ans);
	return 0;
}

void swap(int *x,int *y)//���� 
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void arrange(int det[],int digit[],int temp_digit[],int n,int pos)
{
	//arrange���ý�������a1p1 a2p2...anpn��n��pn�����±꣩�е�p1p2...pn����ȫ���� 
	if(pos==n-1)//�����һλʱ����ʼ�׹�ʽ��������ʽ 
	{
		int term=1;//term����Ϊ1 
		for(int i=0;i<n;i++)//�˴�ѭ���е�i+1��aij��i��digit[i]��j(���������±궼��һ)
		{
			term*=det[i*n+digit[i]-1];//term�ǵ�ǰ���� 
		}
		
		//Ϊ�˲��ı�ԭ���е�˳����Ҫ��һ����ʱ������Ϊԭ���еĸ��� 	
		for(int i=0;i<n;i++)
			temp_digit[i]=digit[i];
		
		cnt=0;//cnt����Ϊ0 
		//����ʱ���鴫��鲢����������ʱ�����ͬʱ���������� 
		mergesort(temp_digit,0,n-1);
		
		term_cnt++;//����+1 
		if(cnt%2==1)//��������Ϊ��������ǰ��ǰ�и��� 
		{
			printf(" -");
			ans=ans-term;
		}
		else if(cnt%2==0)//��������Ϊż������ǰ��ǰ������ 
		{
			printf(" +");
			ans=ans+term;
		}
		for(int i=0;i<n;i++) 
		{
			//��a(i,j)��ʾ����ʽ�е�i�е�j�е�Ԫ��
			//��ÿһ�����ǰ����������ţ������չ�ּ������ 
			printf(" a(%d,%d) ",i+1,digit[i]);
			if(i!=n-1) printf("*");
		}
		printf("\n");
				
	}
	else
	{
		for(int i=pos;i<n;i++)//i�ǵ�ǰλpos�����λ 
		{
			swap(digit+i,digit+pos);//digit[i]��digit[pos]���� 
			arrange(det,digit,temp_digit,n,pos+1);//���뵽��һλ������ 
			swap(digit+i,digit+pos);//��ԭ���������� 
		}
	}
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
			 //��������������������1��ʣ������ĸ���
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


