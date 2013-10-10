#include <iostream>
#include <queue>
using namespace std;

int dequeueAt(queue<int> &q, int count){
	int result;
	for(int i=0;i<count-1;i++) {
		q.push(q.front());
		q.pop();
	}
	result=q.front();
	q.pop();
	return result;
}
void dequeueFor(queue<int> &q, int value){
	int size=q.size();
	for(int i=0;i<size;i++){
		if (value!=q.front()){
			q.push(q.front());
			q.pop();
		}else q.pop();
	}
	return;
}
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	queue<int> a,b;
	for(int i=0;i<n;i++){
		a.push(i+1);
		b.push(n-i);
	}
	int outA,outB;
	while(a.size()>0){
		outA=dequeueAt(a,k);
		outB=dequeueAt(b,m);
		if (outA!=outB) {
			dequeueFor(a,outB);
			dequeueFor(b,outA);
			cout<<outA<<' '<<outB<<'\n';
		}else cout<<outB<<'\n';
	}
	return 0;
}
