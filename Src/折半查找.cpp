// BinSearch.cpp : ��λʵ��2-�۰����-������
// ����BinSearchKey����������ʵ���۰���ҵĴ���

#include <iostream>
using namespace std;

#define MAXNUM 100

class BinSearch {
	public:
		BinSearch();					
		void CreateSequence(int *, int);	//������������
		int  BinSearchKey(int);				//�۰���ҹؼ���
											//��������������Ľ��
		int  BinSuccess;					//�����Ƿ�ɹ���1--�ɹ���0--���ɹ���
		int  BinPos;						//����λ�ã�0��ʾ���ɹ���
		int  BinCount;						//���Ҵ���
	private:
		int  BinList[MAXNUM];				//����� 
		int  MaxKeyCount;					//�������
};

BinSearch::BinSearch()
{

}

void BinSearch::CreateSequence(int *r, int n) //ð������
{
	int i, j, temp;

	MaxKeyCount = n;
	for (i=1; i<n; i++) {
	      if (r[i] < r[i-1]) {
	           temp = r[i];
	           for (j=i-1; j>=0; j-=1) if (temp<r[j]) r[j+1] = r[j]; else break;
	           r[j+1] = temp;
	      }
	}
	for (i=0; i<n; i++) BinList[i] = r[i];

/*	cout << "��������Ϊ��";
	for (i=0; i<n; i++) cout << BinList[i] << ", ";
	cout << endl << endl;*/

}

int BinSearch::BinSearchKey(int Key) //�۰����
{
	int Low, Mid, High;		//�½硢�е㡢�Ͻ�

	Low = 0;				//��ʼ���½�
	High = MaxKeyCount-1;   //��ʼ���Ͻ�
		
	BinSuccess = 0;			//��ʼ�����ҳɹ���־ ��1--�ɹ���0--���ɹ���
	BinPos = 0;				//��ʼ������λ�� ��0��ʾ���ɹ���
	BinCount = 0;			//��ʼ�����Ҵ���
	while (Low <= High) {   //�۰���ң�ֱ��low>highʱ������ʧ��
	//To do: ����whileѭ���������۰���ҵĴ��룬����ע��������Ӧ���룬Ҳ����������ƽṹ
		BinCount++;				   //���Ҵ�����1
		Mid = (Low+High) / 2;	   //��ȷ���е�λ��					
							
		if (Key == BinList[Mid]) { //���Key���е�ֵ���
			BinSuccess = 1;		   //���ò��ҳɹ���־Ϊ1����ʾ���ҳɹ�
			BinPos = Mid+1;		   //���ò���λ��,��ʾ�ڼ���λ�õ�ֵΪKey
			break;				   //�˳�whileѭ�������ҽ���
		}

		if (Key < BinList[Mid]) High = Mid - 1;  //��Key��ֵС���е�ֵ���޸��Ͻ�

		else			        Low  = Mid + 1;  //�����޸��½�		
	}

	return(BinCount);       //���ز��Ҵ���
}



int main(int argc, char* argv[])
{
	int r[MAXNUM];
	int i, j, Key;
	int TestNo, SampleNo;							// �������и��������д�С

	BinSearch *BS = new BinSearch;					// ʵ�����۰����

	cin >> TestNo;									// ������Դ���
	for (i=0; i<TestNo; i++) {
		cin >> SampleNo;							// ����������Ŀ
		for (j=0; j<SampleNo; j++) cin >> r[j];		// �����������ݣ���˳���

		BS->CreateSequence(r, SampleNo);            // ����

		cin  >> Key;								// ����1����������
		BS->BinSearchKey(Key);                      // ����

		cout << BS->BinSuccess << " " << BS->BinPos << " " 
			 << BS->BinCount << endl;	// ������������ 1���ɹ���� 2�����ɹ����ڵڼ���ֵ 3�����Ҵ���
		}
	return 0;
}