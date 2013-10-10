
#include "stdio.h"	
#include <cstdio>	
#include <queue>		//使用C++自带的STL队列

using namespace std;
queue<int> q;

void bank(int l,int time[100])
//银行排队，假设有3个窗口，每个窗口最多容纳m个顾客排队，共有l个顾客
{
	int i, j;
	int w=3, m=5;
	int first,last;
	if (w*m <l) {
		printf("超出最大服务数量！\n");
		exit(-1);
	}
	queue<int> window[3];
	j=0;
	i=0;
	while (j<l) {
		if (window[i].size()>=m) {	//检查第i个窗口的队伍是否已满，如果满了切换窗口
			i++;
			if (i%w == 0) i=0;
		}
		else {
			window[i].push(j+1001);		//加入当前窗口排队
			j++;
			i++;	//下一位顾客切换到另一个窗口
			if (i%w == 0) i=0;
		}
	}
	for (i=0; i<3; i++) {	//输出每个队列排队情况
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
	printf("请输入数据个数和数值\n");
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

