
#include "stdio.h"	
#include <cstdio>	
#include <queue>		//ʹ��C++�Դ���STL����

using namespace std;
queue<int> q;

void bank(int l,int time[100])
//�����Ŷӣ�������3�����ڣ�ÿ�������������m���˿��Ŷӣ�����l���˿�
{
	int i, j;
	int w=3, m=5;
	int first,last;
	if (w*m <l) {
		printf("����������������\n");
		exit(-1);
	}
	queue<int> window[3];
	j=0;
	i=0;
	while (j<l) {
		if (window[i].size()>=m) {	//����i�����ڵĶ����Ƿ���������������л�����
			i++;
			if (i%w == 0) i=0;
		}
		else {
			window[i].push(j+1001);		//���뵱ǰ�����Ŷ�
			j++;
			i++;	//��һλ�˿��л�����һ������
			if (i%w == 0) i=0;
		}
	}
	for (i=0; i<3; i++) {	//���ÿ�������Ŷ����
		if(!window[i].empty())
			first=window[i].front();
		while(!window[i].empty()) {	
			printf("%d ", window[i].front());
			last=window[i].front();
			window[i].pop();
		}
		printf("%d ",time[first-1001]);
		printf("%d",time[last-1001]);
		printf("\n");
	}
}



int main(int argc, char* argv[])
{
	
	int i=0, temp=0, n=0;
	int time[100];

/*	
	printf("���������ݸ�������ֵ\n");
	scanf("%d", &n);	
	for (i=0; i<n; i++) {
		scanf("%d", &temp);
		q.push(temp);
	}
	while(!q.empty()) {	
		printf("%d ", q.front());
		q.pop();
	}
*/	
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d",&time[i]);
	bank(n,time);
	
	printf("\n");
	return 0;
}

