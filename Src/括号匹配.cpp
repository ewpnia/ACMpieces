#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int cases; //用例个数	
	bool error; //出错标志，一旦发现有右括号不被匹配，可提前输出错误，停止匹配

	cin>>cases; //输入用例个数

	for(int i=0;i<cases;i++){
		stack<char> s; //定义一个栈
		error=false; //初始化不匹配

		string str; //当前用例字符串
		cin>>str; //输入字符串
		for(int j=0; j<str.length(); j++){
			switch (str[j]) {
				case '(': 
					s.push(str[j]);//进栈
					break;
				case '[' : 
					s.push(str[j]);//进栈
					break;
				case '{' :
					s.push(str[j]);//进栈
					break;
				case ')' : 
					if (s.empty()||s.top()!='(') //不匹配
						error=true; //报错
					else //匹配
						s.pop(); //出栈
					break;
				case ']' :
					if (s.empty()||s.top()!='[') //不匹配
						error=true; //报错
					else //匹配
						s.pop(); //出栈
					break;
				case '}' : 
					if (s.empty()||s.top()!='{') //不匹配
						error=true; //报错
					else //匹配
						s.pop(); //出栈
					break;
			}

			if(error) //若已经出错
				break; //直接跳出for循环
		}

		//输出结果
		if (error||!s.empty()) //错误，或者结束时栈不空
			cout<<"error\n";
		else //正确
			cout<<"ok\n";
	}
}