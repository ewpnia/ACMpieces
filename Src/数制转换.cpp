#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main(){

	stack<int> s; //��������
	queue<int> q; //С������
	
	int cases;  //��ת������
	cin>>cases;
	
	double origin, epslon=10E-5;
	int k;

	for(int i=0;i<cases;i++){
		cin>>origin>>k; //��ת����������

		//��������
		int IntPart=(int)(origin+epslon);
		while(IntPart!=0){
			s.push(IntPart%k); //��ջ
			IntPart /=k;
		}
		
		//С������
		double DecimalPart=origin-int(origin+epslon);

		while(DecimalPart>epslon){ //����С������
			DecimalPart*=k;
			int temp=(int)(DecimalPart+epslon);
			if (temp>=0)	 {
				q.push(temp); //����
			}
			DecimalPart-=temp;

			if(q.size() >= 32) //ѭ��С���ض�
				break;
		}			

		//�����������
		while(!s.empty()) {
			int temp=s.top(); //��ջ
			s.pop();
			if (temp<10) cout<<temp;
			else cout<<char(int('A')+temp-10);
		}

		//���С������
		if(!q.empty())
		{
			//��
			cout<<'.';

			//С��
			while(!q.empty())
			{
				int temp = q.front(); //ȡ��ͷԪ��
				if (temp<10)  cout<<temp;
				else cout<<char(int('A')+temp-10);
				q.pop(); //����
			}
		}

		cout<<'\n';
	}
	return 0;
}