/* Dijkstra算法描述
1、S[0] ＝ 1 ；// 结点 V0 最短路径已求得,是源点。
2、for ( i=1; i<n; i++  )  
3、  { D[i]=c[ 0, i ]; S[i]=0; Path[ v ]  = -1; } 
4、for ( i=1; i<n; i++  ) 
5、{  在 V－S 中选择一个结点VW；使得
         D[w] 最小。将W 加入集合 S // 用最小化堆选
6、    for (每一个在 V－S 中的结点 V ) //出最小的
6.5          { if  (D[w]+C[w,v] < D[v ]) Path[ v ] = w; 
7、            D[v]=MIN( D[v],D[w]+C[w,v]) 
8             };   //如用最小化堆实现，此处还要调整堆
9、 }
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
	const int MaxLen=100;
	//输入
	int k;
	cin>>k;
	int matrix[MaxLen][MaxLen];
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>matrix[i][j];

	//Dijkstra算法实现
	int S[MaxLen],Path[MaxLen],D[MaxLen];
	for(int i=0;i<k;i++) {
		D[i]=matrix[0][i];
		S[i]=0;
		Path[i]=-1;
	}
	S[0]=1;
	for(int i=1; i<k;i++){
		int w=-1,dw=-1;
		for(int j=0;j<k;j++){
			if ((S[j]==0)&&(D[j]!=0)&&((w==-1)||(D[j]<dw))){
				w=j;
				dw=D[j];
			}
		}
		if (w==-1) break;  //没有通路

		//计算由新的最短路径顶点引起的变化
		S[w]=1; 
		for(int j=0;j<k;j++){
			if ((S[j]==0)&&(matrix[w][j]!=0)){
				if ((D[j]==0)||(D[w]+matrix[w][j]<D[j])){
					Path[j]=w;
					D[j]=D[w]+matrix[w][j];
				}
			}
		}

		//输出结果
		if (w==1){
			stack<int> result;
			while(w!=-1){
				result.push(w);
				w=Path[w];
			}
			cout<<'0';
			while(!result.empty()){
				cout<<' '<<result.top();
				result.pop();
			}
			cout << endl << D[1] <<endl;
			return 0;
		}
	}
	return 0;
}