#include <iostream>
#include <queue>

using namespace std;

int main(){
	const int MaxLen=100;
	//输入
	int cases;
	cin>>cases;
	for(int x=0;x<cases;x++){
		int k;
		cin>>k;
		int matrix[MaxLen][MaxLen];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				cin>>matrix[i][j];
		
		//连通图判断
		bool visited[MaxLen];
		for(int i=0;i<k;i++) visited[i]=false; //初始化访问，初始时所有的节点都未被访问
		queue<int> q;
		q.push(0); //初始化队列
		int connectedNum=0; //连通节点数目
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

		//输出结果
		if (connectedNum==k) 
			cout<<"Yes\n"; 
		else
			cout<<"No\n";
	}
	
	return 0;
}