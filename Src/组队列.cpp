// sample.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <queue>
#include <set> //�����࣬����������
using namespace std;

#define MaxLen 100
int main(){

	set<int> group[MaxLen]; //������
	queue<int> subgroupQueue[MaxLen]; //�������ڶ����д��ڵ�Ԫ��
	queue<queue<int>*> totalQueue; //����

	//��ʼ��������
	int cases;
	cin>>cases; //����
	for(int i=0;i<cases;i++){
		int setNum; //����Ԫ�ظ���
		cin>>setNum;
		for(int j=0;j<setNum;j++){
			int temp;
			cin>>temp; //����Ԫ��
			group[i].insert(temp); //��������Ԫ��
		}
	}

	//��ʼ�����������
	string s;
	int current;
	cin>>s;
	while(s!="STOP"){ //δֹͣ
		if (s=="ENQUEUE"){ //����
			cin>>current;
			for(int i=0;i<cases;i++){ //���������
				if (group[i].find(current)!=group[i].end()){
					if (subgroupQueue[i].empty()){
						totalQueue.push(&subgroupQueue[i]); //������ͬ��Ԫ���ڶ����У������鵽��β
						subgroupQueue[i].push(current); //����Ԫ��
					}
					else{
						subgroupQueue[i].push(current); //�Ѿ�����ͬ��Ԫ���ڶ����У����뵽ͬ��ĩβ
					}
				}
			}
		}else{ //���� s=="DEQUEUE"
			totalQueue.front()->pop(); //��ͷ����еĶ�ͷԪ�س���
			if (totalQueue.front()->empty()) totalQueue.pop(); //��ͷ�����Ϊ�գ���ͷ����г���
		}
		cin>>s;
	}
	while(!totalQueue.empty()){ //������
		cout<<totalQueue.front()->front(); //�����ͷ����еĶ�ͷԪ��
		totalQueue.front()->pop(); //��ͷ����еĶ�ͷԪ�س���
		if (totalQueue.front()->empty())totalQueue.pop();//���ͷ�����Ϊ�գ���ͷ����г���
		if (!totalQueue.empty()) cout<<' ';//����ո�
	}
}