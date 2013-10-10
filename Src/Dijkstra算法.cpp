/* Dijkstra�㷨����
1��S[0] �� 1 ��// ��� V0 ���·�������,��Դ�㡣
2��for ( i=1; i<n; i++  )  
3��  { D[i]=c[ 0, i ]; S[i]=0; Path[ v ]  = -1; } 
4��for ( i=1; i<n; i++  ) 
5��{  �� V��S ��ѡ��һ�����VW��ʹ��
         D[w] ��С����W ���뼯�� S // ����С����ѡ
6��    for (ÿһ���� V��S �еĽ�� V ) //����С��
6.5          { if  (D[w]+C[w,v] < D[v ]) Path[ v ] = w; 
7��            D[v]=MIN( D[v],D[w]+C[w,v]) 
8             };   //������С����ʵ�֣��˴���Ҫ������
9�� }
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
	const int MaxLen=100;
	//����
	int k;
	cin>>k;
	int matrix[MaxLen][MaxLen];
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>matrix[i][j];

	//Dijkstra�㷨ʵ��
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
		if (w==-1) break;  //û��ͨ·

		//�������µ����·����������ı仯
		S[w]=1; 
		for(int j=0;j<k;j++){
			if ((S[j]==0)&&(matrix[w][j]!=0)){
				if ((D[j]==0)||(D[w]+matrix[w][j]<D[j])){
					Path[j]=w;
					D[j]=D[w]+matrix[w][j];
				}
			}
		}

		//������
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