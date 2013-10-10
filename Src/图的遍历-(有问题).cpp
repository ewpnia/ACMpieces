#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	//输入
	const int MaxLen=100;
	int k;
	cin>>k;
	int matrix[MaxLen][MaxLen];
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>matrix[i][j];
	cout << endl;

	//DFS-深度优先遍历图
	bool visited[MaxLen];
	stack<int> s;
	for(int i=k-1;i>=0;i--) s.push(i); //初始化堆栈
	for(int i=0;i<k;i++) visited[i]=false; //初始化访问标志，开始时，所有节点都未被访问	
	cout << "深度优先遍历结果："<< endl;
	//遍历
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

	//BFS-广度优先遍历图
	for(int i=0;i<k;i++) visited[i]=false; //初始化访问标志，开始时，所有节点都未被访问
	queue<int> q;
	q.push(0); //初始化队列
	cout << "广度优先遍历结果："<< endl;
	//遍历
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