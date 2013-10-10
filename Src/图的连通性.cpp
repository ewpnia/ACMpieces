#include <iostream>
#include <queue>

using namespace std;

int main(){
	const int MaxLen=100;
	//����
	int cases;
	cin>>cases;
	for(int x=0;x<cases;x++){
		int k;
		cin>>k;
		int matrix[MaxLen][MaxLen];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				cin>>matrix[i][j];
		
		//��ͨͼ�ж�
		bool visited[MaxLen];
		for(int i=0;i<k;i++) visited[i]=false; //��ʼ�����ʣ���ʼʱ���еĽڵ㶼δ������
		queue<int> q;
		q.push(0); //��ʼ������
		int connectedNum=0; //��ͨ�ڵ���Ŀ
		while(!q.empty()){
			int currentNode=q.front();
			q.pop();
			if (!visited[currentNode]){
				visited[currentNode]=true;
				connectedNum++;
				for(int j=0;j<k;j++){
					if ((matrix[currentNode][j]==1)&&(!visited[j]))
						q.push(j);
				}
			}
		}

		//������
		if (connectedNum==k) 
			cout<<"Yes\n"; 
		else
			cout<<"No\n";
	}
	
	return 0;
}