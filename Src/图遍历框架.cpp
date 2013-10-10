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
	//�����ڽӾ�������
	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
			cin>>matrix[i][j];

	//��������㷨DFS
	bool visited[MaxLen];
	stack<int> s;	

	for(i=k-1;i>=0;i--) 
		s.push(i);	//������Ԫ����ѹ���ջ
	for(i=0;i<k;i++) 
		visited[i]=false;

	while(!s.empty()){	  	//to-do dfs
		i=s.top();//ȡ��1�����
		s.pop();//����ջ
		if (visited[i]==false)//������δ���ʹ�
		{
			visited[i]=true;//���ý��Ϊ�ѷ���
			if (i!=0)	
				cout<<' ';//��������׽�㣬���1���ո�
			cout<<i;	//�����ǰ�����
		}	
		for(j=k-1;j>i;j--)//�Ѹý�������ӵ�����δ���ʽ��ѹ���ջ��ע���ջ˳��
			if(matrix[i][j]==1)	
				s.push(j);
	}
	cout<<endl;


	//��������㷨BFS
	for(i=0;i<k;i++) 
		visited[i]=false;
	queue<int> q;
	q.push(0);
	do{  //to-do bfs		
		if(!q.empty())//������δ��
		{
			i=q.front();//�Ӷ���ȡ��1�����
			q.pop();//��������
		}
		if (visited[i]==false)//������δ���ʹ�
		{	
			visited[i]=true;//���ý��Ϊ�ѷ���
			if (i!=0)	
				cout<<' ';//��������׽�㣬���1���ո�
			cout<<i;//�����ǰ�����
		}
		for(j=i+1;j<k;j++)//�Ѹý�������ӵ�����δ���ʽ�������У�ע�����˳��
			if(matrix[i][j]==1)	
				q.push(j);
		for(;i<k;i++)
			if(visited[i]==false)
				q.push(i);//��δ���ʵĽ��ȫ��������У�����ѭ��
	}while(!q.empty());
	cout<<endl;

	return 0;
}