#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	const int MaxLen=100;
	int k;
	int i,j;
	cin>>k;
	int matrix[MaxLen][MaxLen];
	//输入邻接矩阵数据
	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
			cin>>matrix[i][j];

	//深度优先算法DFS
	bool visited[MaxLen];
	stack<int> s;	

	for(i=k-1;i>=0;i--) 
		s.push(i);	//把所有元素先压入堆栈
	for(i=0;i<k;i++) 
		visited[i]=false;

	while(!s.empty()){	  	//to-do dfs
		i=s.top();//取出1个结点
		s.pop();//结点出栈
		if (visited[i]==false)//如果结点未访问过
		{
			visited[i]=true;//设置结点为已访问
			if (i!=0)	
				cout<<' ';//如果不是首结点，输出1个空格
			cout<<i;	//输出当前结点编号
		}	
		for(j=k-1;j>i;j--)//把该结点相连接的所有未访问结点压入堆栈，注意进栈顺序
			if(matrix[i][j]==1)	
				s.push(j);
	}
	cout<<endl;


	//广度优先算法BFS
	for(i=0;i<k;i++) 
		visited[i]=false;
	queue<int> q;
	q.push(0);
	do{  //to-do bfs		
		if(!q.empty())//当队列未空
		{
			i=q.front();//从队列取出1个结点
			q.pop();//结点出队列
		}
		if (visited[i]==false)//如果结点未访问过
		{	
			visited[i]=true;//设置结点为已访问
			if (i!=0)	
				cout<<' ';//如果不是首结点，输出1个空格
			cout<<i;//输出当前结点编号
		}
		for(j=i+1;j<k;j++)//把该结点相连接的所有未访问结点加入队列，注意进队顺序
			if(matrix[i][j]==1)	
				q.push(j);
		for(;i<k;i++)
			if(visited[i]==false)
				q.push(i);//把未访问的结点全部加入队列，继续循环
	}while(!q.empty());
	cout<<endl;

	return 0;
}