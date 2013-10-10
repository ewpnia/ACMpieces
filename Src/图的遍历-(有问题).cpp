#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	//����
	const int MaxLen=100;
	int k;
	cin>>k;
	int matrix[MaxLen][MaxLen];
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>matrix[i][j];
	cout << endl;

	//DFS-������ȱ���ͼ
	bool visited[MaxLen];
	stack<int> s;
	for(int i=k-1;i>=0;i--) s.push(i); //��ʼ����ջ
	for(int i=0;i<k;i++) visited[i]=false; //��ʼ�����ʱ�־����ʼʱ�����нڵ㶼δ������	
	cout << "������ȱ��������"<< endl;
	//����
	while(!s.empty()){
		int currentNode=s.top();
		s.pop();
		if (!visited[currentNode]){
			visited[currentNode]=true;
			if (currentNode!=0) cout<<' ';
			cout<<currentNode;
			for(int j=k-1;j>=0;j--){
				if ((matrix[currentNode][j]==1)&&(!visited[j]))
					s.push(j);
			}
		}
	}
	cout<<endl;

	//BFS-������ȱ���ͼ
	for(int i=0;i<k;i++) visited[i]=false; //��ʼ�����ʱ�־����ʼʱ�����нڵ㶼δ������
	queue<int> q;
	q.push(0); //��ʼ������
	cout << "������ȱ��������"<< endl;
	//����
	do{
		while(!q.empty()){
			int currentNode=q.front();
			q.pop();
			if (!visited[currentNode]){
				visited[currentNode]=true;
				if (currentNode!=0) cout<<' ';
				cout<<currentNode;
				for(int j=0;j<k;j++){
					if ((matrix[currentNode][j]==1)&&(!visited[j]))
						q.push(j);
				}
			}
		}

		for (int i=0;i<k;i++) if (!visited[i]) {
			q.push(i);
			break;
		}
	}while(!q.empty());

	cout<<endl;

	return 0;
}