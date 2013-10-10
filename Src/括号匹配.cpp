#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int cases; //��������	
	bool error; //�����־��һ�������������Ų���ƥ�䣬����ǰ�������ֹͣƥ��

	cin>>cases; //������������

	for(int i=0;i<cases;i++){
		stack<char> s; //����һ��ջ
		error=false; //��ʼ����ƥ��

		string str; //��ǰ�����ַ���
		cin>>str; //�����ַ���
		for(int j=0; j<str.length(); j++){
			switch (str[j]) {
				case '(': 
					s.push(str[j]);//��ջ
					break;
				case '[' : 
					s.push(str[j]);//��ջ
					break;
				case '{' :
					s.push(str[j]);//��ջ
					break;
				case ')' : 
					if (s.empty()||s.top()!='(') //��ƥ��
						error=true; //����
					else //ƥ��
						s.pop(); //��ջ
					break;
				case ']' :
					if (s.empty()||s.top()!='[') //��ƥ��
						error=true; //����
					else //ƥ��
						s.pop(); //��ջ
					break;
				case '}' : 
					if (s.empty()||s.top()!='{') //��ƥ��
						error=true; //����
					else //ƥ��
						s.pop(); //��ջ
					break;
			}

			if(error) //���Ѿ�����
				break; //ֱ������forѭ��
		}

		//������
		if (error||!s.empty()) //���󣬻��߽���ʱջ����
			cout<<"error\n";
		else //��ȷ
			cout<<"ok\n";
	}
}