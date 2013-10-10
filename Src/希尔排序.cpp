//ShellSort.cpp 希尔排序类
//请在Shellsort::Shellsort函数内根据提示填入代码

#include<iostream>
using namespace std;

//希尔排序类
class ShellSort{
private:
	int *pnum; 							//指针用以指定待排序指定排序数据
	int *d;								//指针用以指定所需的增量
	int max;
	int row;
public:
	void Size(int n);					//动态分配内存空间，用于存储待排序数据
	void Delete();						//删除所分配的内存
	void Value(int* value, int n);		//对数据赋值
	void Output(int n);					//对打印数据
	int DValue(int n);					//计算希尔排序增量
	void Shellsort(int n, int numOfD);	//希尔排序
};



//动态开辟内存空间，用你存储待排序数据
void ShellSort::Size(int n)
{
	pnum = new int[n];
	max=n;
	row=0;
}


//删除所分配的内存
void ShellSort::Delete()
{
	delete [] pnum;
	delete [] d;
}


//对数据赋值
void ShellSort::Value(int* value, int n)
{
	int max=sizeof(pnum)/sizeof(int);
	for(int i=0; i<n; i++)
		pnum[i]=value[i];
}


//对打印数据
void ShellSort::Output(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<pnum[i]<<" ";
	}
	cout<<endl;
}

//参数n是样本数据个数，数组d[]保存所需的各个增量值gap
int ShellSort::DValue(int n) 
{
	int flag=0; //增量值的个数
	int max=n; 

	while(n != 1) //计算增量值的个数
	{
		n=n/2;
		flag++;
	}
	d = new int[flag]; //增量值数组

	for(int i=0; i<flag; i++) //计算增量值
	{
		max=max/2;
		d[i]=max; //装入增量值
	}
	return flag; //返回增量值的个数
}

///希尔排序函数，a[]为所需进行排序的数组元素，n指定所需排序的元素个数
//d[]存放希尔排序中增量值，numOfD指明d[]增量的元素个数
void ShellSort::Shellsort(int n, int numOfD)
//用希尔排序法对记录a[0]--a[n-1]排序
//各组内采用直接插入法排序
{
	int i, j, k, m; 
	int gap,row=0;	//gap表示增量值，也就是取子序列的间隔； row为第几次插入排序
	long temp;

	for(m = 0; m < numOfD; m++)
	{
		gap = d[m];              //取增量中的值，赋给gap
		for(k = 0; k < gap; k++) //循环比较值，单次排序所需要的循环次数，循环次数就是增量值的大小，就是子序列的个数
		{
			for(i = k; i < n-gap; i = i+gap) //直接插入排序的过程
			{
				temp = pnum[i+gap];			 //取temp值,
				j = i;						 //设置开始比较的位置j
				while(j >= 0 && temp <= pnum[j]) //插入排序后的顺移
				{
					pnum[j+gap] = pnum[j];	//顺移
					j = j-gap;				//修改j
				}
				pnum[j+gap] = temp;			//插入temp的值				
			}
		}
		row++;								//插入排序次数加1
		if( row ==1) { Output(max);}      //输出第一次排序的结果
	}
}

int main()
{
	int numOfD = 0;				//希尔排序增量值
	int aprime;					//保存待排序样本数据的个数的变量
	int x;						//保存样本数据的组数的变量
	ShellSort text;				//实例化ShellSort的对象text
	cin>>x;						//输入样本数据的组数
	for(int j=0; j<x; j++)
	{
		int flag=0;
		cin >> aprime;						//输入样本数据的个数

		int numOfD=text.DValue(aprime);		//计算希尔排序所需的增量个数和各个增量值

		text.Size(aprime);

		int *num = new int[aprime];
		for(int i=0; i<aprime; i++)			//输入一组样本数据
			cin>>num[i];

		text.Value(num,aprime);				//数据传给希尔排序
		text.Shellsort(aprime, numOfD);		//希尔排序
		text.Output(aprime);				//输出排序结果

		text.Delete();						//释放内存
		delete [] num;
	}
	return 0;
}