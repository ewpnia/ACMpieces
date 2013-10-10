// sample.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <queue>
#include <set> //集合类，定义组属性
using namespace std;

#define MaxLen 100
int main(){

	set<int> group[MaxLen]; //组属性
	queue<int> subgroupQueue[MaxLen]; //各个组在队列中存在的元素
	queue<queue<int>*> totalQueue; //队列

	//初始化组属性
	int cases;
	cin>>cases; //组数
	for(int i=0;i<cases;i++){
		int setNum; //组中元素个数
		cin>>setNum;
		for(int j=0;j<setNum;j++){
			int temp;
			cin>>temp; //组中元素
			group[i].insert(temp); //插入组中元素
		}
	}

	//开始输入队列命令
	string s;
	int current;
	cin>>s;
	while(s!="STOP"){ //未停止
		if (s=="ENQUEUE"){ //进队
			cin>>current;
			for(int i=0;i<cases;i++){ //检查组属性
				if (group[i].find(current)!=group[i].end()){
					if (subgroupQueue[i].empty()){
						totalQueue.push(&subgroupQueue[i]); //不存在同组元素于队列中，插入组到队尾
						subgroupQueue[i].push(current); //插入元素
					}
					else{
						subgroupQueue[i].push(current); //已经存在同组元素于队列中，插入到同组末尾
					}
				}
			}
		}else{ //出队 s=="DEQUEUE"
			totalQueue.front()->pop(); //队头组队列的队头元素出队
			if (totalQueue.front()->empty()) totalQueue.pop(); //队头组队列为空，队头组队列出列
		}
		cin>>s;
	}
	while(!totalQueue.empty()){ //输出结果
		cout<<totalQueue.front()->front(); //输出队头组队列的队头元素
		totalQueue.front()->pop(); //队头组队列的队头元素出队
		if (totalQueue.front()->empty())totalQueue.pop();//如队头组队列为空，队头组队列出列
		if (!totalQueue.empty()) cout<<' ';//间隔空格
	}
}