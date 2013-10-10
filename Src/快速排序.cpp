//Quicksort.cpp ����������
//����Quicksort::QuickSort�����ڸ���ע��������Ӧ�Ĵ��룬ÿ��ע�Ͷ�Ӧһ�д��룬��9�д���

#include<iostream>
using namespace std; //ʹ��C++��׼�����ռ䣬���ڵ���iostream��C++�⺯�����粻ʹ�ñ�׼�����ռ�ᱨ��

class Quicksort{
private:
	int *pnum;							//ָ������ָ��������ָ����������
	int max;
	int row;
public:
	void Size(int n);					//��̬�����ڴ�ռ䣬���ڴ洢����������
	void Delete();						//ɾ����������ڴ�
	void Value(int* value, int n);		//�����ݸ�ֵ
	void Output(int n);					//�Դ�ӡ����
	void QuickSort(int low, int hight);	//ð������
};



//��̬�����ڴ�ռ䣬���ڴ洢����������
void Quicksort::Size(int n)
{
	pnum = new int[n];
	max=n;
	row=0;
}


//ɾ����������ڴ�
void Quicksort::Delete()
{
	delete [] pnum;
}


//�����ݸ�ֵ
void Quicksort::Value(int* value, int n)
{
	int max=sizeof(pnum)/sizeof(int);
	for(int i=0; i<n; i++)
		pnum[i]=value[i];
}


//��ӡ������
void Quicksort::Output(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<pnum[i]<<" ";
	}
	cout<<endl;
}

void Quicksort::QuickSort(int low, int high)
//�õݹ鷽���Զ���a[low]--a[high]���п�������
{
	//To do: �����ע��������Ӧ�Ĵ��룬ÿ��ע�Ͷ�Ӧһ�д��룬��9�д���

	int i, j;			//��low����high��λ��
	long temp;
	i = low;			//ָ���±�ֵ��ͨ���Ǵ�������������λ��ע��Ӵ�i�ʹ�����low�� ��low��ֵ����
	j = high;			//ָ���±�ֵ��ͨ���Ǵ�������������λ��ע��Ӵ�j�ʹ�����high, ��high��ֵ����

	//ע�⣬i��j�Ӵ˷ֱ���������low����high���������ж���low����high�Ĳ�������ֻ��i��j�������мǣ�����

	temp = pnum[low];	//��

	while(i < j)        //����high>��low��ʱ��ѭ��,Ҳ���� j > i��ʱ��ѭ��������low=��highʱ��Ҳ����i=jʱ���˳�
	{
		//��������Ҷ�ɨ��
		while(i < j && temp <= pnum[j]) //Ѱ����high��ߵ�һ��С���ࣨtemp����ֵ
			j--;			  //��1�У����ƣ���high��1
		if(i < j) //�����low < ��high, ����
		{
			pnum[i] = pnum[j];//��2�У����ҵ���ֵ������lowָ���λ��
			i++;			  //��3�У���low+1
		}

		//����������ɨ��
		while(i < j && pnum[i] <= temp) //Ѱ����lo�ұߵ�һ��������temp��ֵ
			i++;			 //��4�У����ƣ���low��1
		if(i < j) //�����low < ��high, ����
		{
			pnum[j] = pnum[i];//��5�У����ҵ���ֵ������highָ���λ��
			j--;			  //��6�У���high-1
		}
	}

	pnum[i] = temp; //��7�У�����temp������lowָ���λ��

	row++;			//�������+1
	if(row == 1)	//�����һ�������Ľ��
	{
		Output(max);
	}

	//���Ӷ���������еݹ��������
	if(low < i) //��low < ��low
		QuickSort(low, i-1); //��8�У��ݹ���������������У� �� ��low �� ��low-1 Ϊ��������
	if(i < high)//��high < ��high
		QuickSort(j+1, high);//��9�У��ݹ���������������У� �� ��high+1 �� ��high Ϊ��������
}

int main()
{
	int low, high;			//�������λ,���λ
	int x;					//���Ա�������������ݵ�����
	int aprime;				//���Ա�������������ݵĸ���
	Quicksort text;			//����Quicksort��Ķ���text

	cin>>x;					//�����������ݵ�����
	for(int j=0; j<x; j++)
	{
		cin>>aprime;		//���뵥���������ݵĸ���
		text.Size(aprime);	//�����ڴ�ռ����Ա�����������
		int *num = new int[aprime];	//�ݴ���������
		for(int i=0; i<aprime; i++)
		{
			cin>>num[i];//�Խ��������ݸ�ֵ����ʱ������
		}

		text.Value(num,aprime); //���������������ݷ���������׼������

		low = 0;				//�����������λ
		high = aprime-1;		//�����������λ
		text.QuickSort(low, high);//���ÿ���������������ݽ�������

		text.Output(aprime);//������

		text.Delete();//�ͷ��ڴ�
		delete [] num;//�ͷ��ڴ�
	}
	return 0;
}