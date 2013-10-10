#include <iostream>
#include <stack>

using namespace std;
#define Max 20
typedef struct {
	int x,y,d;
}state;
int main(){

	int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	stack<state> s;
	int maze[Max][Max];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>maze[i][j];
	state currentState={0,0,-1},nextState;
	s.push(currentState);
	maze[0][0]=1;
	while(!s.empty()){
		currentState=s.top();
		s.pop();
		if (currentState.d!=-1) {
			maze[currentState.x+directions[currentState.d][0]][currentState.y+directions[currentState.d][1]]=0;	
		}
		while(currentState.d<4){
			currentState.d++;
			nextState.x=currentState.x+directions[currentState.d][0];
			nextState.y=currentState.y+directions[currentState.d][1];
			nextState.d=-1;
			if ( (0<=nextState.x)&&(nextState.x<n)&&
				 (0<=nextState.y)&&(nextState.y<n)&&
				 (maze[nextState.x][nextState.y]==0)){
					 maze[nextState.x][nextState.y]=1;
					 s.push(currentState);
					 currentState=nextState;
			}
			if ((nextState.x==n-1)&&(nextState.y==n-1)){
				stack<state> result;
				while(!s.empty()){
					result.push(s.top());
					s.pop();
				}
				while(!result.empty()){
					cout<<result.top().x<<' '<<result.top().y<<'\n';
					result.pop();
				}
				cout<<n-1<<' '<<n-1<<'\n';
				return 0;
			}
		}
	}
	cout<<"noway\n";
	return 0;
}