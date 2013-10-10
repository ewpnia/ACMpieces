#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main(){

	stack<int> s; //整数部分
	queue<int> q; //小数部分
	
	int cases;  //需转换个数
	cin>>cases;
	
	double origin, epslon=10E-5;
	int k;

	for(int i=0;i<cases;i++){
		cin>>origin>>k; //被转换数，进制

		//整数部分
		int IntPart=(int)(origin+epslon);
		while(IntPart!=0){
			s.push(IntPart%k); //进栈
			IntPart /=k;
		}
		
		//小数部分
		double DecimalPart=origin-int(origin+epslon);

		while(DecimalPart>epslon){ //存在小数部分
			DecimalPart*=k;
			int temp=(int)(DecimalPart+epslon);
			if (temp>=0)	 {
				q.push(temp); //进队
			}
			DecimalPart-=temp;

			if(q.size() >= 32) //循环小数截断
				break;
		}			

		//输出整数部分
		while(!s.empty()) {
			int temp=s.top(); //出栈
			s.pop();
			if (temp<10) cout<<temp;
			else cout<<char(int('A')+temp-10);
		}

		//输出小数部分
		if(!q.empty())
		{
			//点
			cout<<'.';

			//小数
			while(!q.empty())
			{
				int temp = q.front(); //取队头元素
				if (temp<10)  cout<<temp;
				else cout<<char(int('A')+temp-10);
				q.pop(); //出队
			}
		}

		cout<<'\n';
	}
	return 0;
}