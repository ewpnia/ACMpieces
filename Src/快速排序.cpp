//Quicksort.cpp 快速排序类
//请在Quicksort::QuickSort函数内根据注释填入相应的代码，每行注释对应一行代码，共9行代码

#include<iostream>
using namespace std; //使用C++标准命名空间，由于调用iostream的C++库函数，如不使用标准命名空间会报错

class Quicksort{
private:
	int *pnum;							//指针用以指定待排序指定排序数据
	int max;
	int row;
public:
	void Size(int n);					//动态分配内存空间，用于存储待排序数据
	void Delete();						//删除所分配的内存
	void Value(int* value, int n);		//对数据赋值
	void Output(int n);					//对打印数据
	void QuickSort(int low, int hight);	//冒泡排序
};



//动态分配内存空间，用于存储待排序数据
void Quicksort::Size(int n)
{
	pnum = new int[n];
	max=n;
	row=0;
}


//删除所分配的内存
void Quicksort::Delete()
{
	delete [] pnum;
}


//对数据赋值
void Quicksort::Value(int* value, int n)
{
	int max=sizeof(pnum)/sizeof(int);
	for(int i=0; i<n; i++)
		pnum[i]=value[i];
}


//打印排序结果
void Quicksort::Output(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<pnum[i]<<" ";
	}
	cout<<endl;
}

void Quicksort::QuickSort(int low, int high)
//用递归方法对对象a[low]--a[high]进行快速排序
{
	//To do: 请根据注释填入相应的代码，每行注释对应一行代码，共9行代码

	int i, j;			//新low和新high的位置
	long temp;
	i = low;			//指定下标值，通常是待排序数组的最低位，注意从此i就代表新low， 旧low的值不变
	j = high;			//指定下标值，通常是待排序数组的最高位，注意从此j就代表新high, 旧high的值不变

	//注意，i，j从此分别代表的是新low和新high，后面所有对新low和新high的操作，都只对i和j操作，切记！！！

	temp = pnum[low];	//枢

	while(i < j)        //当新high>新low的时候循环,也就是 j > i的时候循环，当新low=新high时，也就是i=j时，退出
	{
		//在数组的右端扫描
		while(i < j && temp <= pnum[j]) //寻找新high左边第一个小于枢（temp）的值
			j--;			  //第1行：左移，新high减1
		if(i < j) //如果新low < 新high, 交换
		{
			pnum[i] = pnum[j];//第2行：把找到的值赋给新low指向的位置
			i++;			  //第3行：新low+1
		}

		//在数组的左端扫描
		while(i < j && pnum[i] <= temp) //寻找新lo右边第一个大于枢temp的值
			i++;			 //第4行：右移，新low加1
		if(i < j) //如果新low < 新high, 交换
		{
			pnum[j] = pnum[i];//第5行：把找到的值赋给新high指向的位置
			j--;			  //第6行：新high-1
		}
	}

	pnum[i] = temp; //第7行：把枢temp赋给新low指向的位置

	row++;			//排序次数+1
	if(row == 1)	//输出第一次排序后的结果
	{
		Output(max);
	}

	//对子对象数组进行递归快速排序
	if(low < i) //旧low < 新low
		QuickSort(low, i-1); //第8行：递归快速排序左子序列， 从 旧low 到 新low-1 为左子序列
	if(i < high)//旧high < 新high
		QuickSort(j+1, high);//第9行：递归快速排序右子序列， 从 新high+1 到 旧high 为右子序列
}

int main()
{
	int low, high;			//排序最低位,最高位
	int x;					//用以保存待排样本数据的组数
	int aprime;				//用以保存待排样本数据的个数
	Quicksort text;			//开辟Quicksort类的对象text

	cin>>x;					//输入样本数据的组数
	for(int j=0; j<x; j++)
	{
		cin>>aprime;		//输入单组样本数据的个数
		text.Size(aprime);	//开辟内存空间用以保存样本数据
		int *num = new int[aprime];	//暂存样本数据
		for(int i=0; i<aprime; i++)
		{
			cin>>num[i];//对将样本数据赋值到临时变量中
		}

		text.Value(num,aprime); //将待排序样本数据放入数组中准备排序

		low = 0;				//设置排序最低位
		high = aprime-1;		//设置排序最高位
		text.QuickSort(low, high);//调用快速排序对样本数据进行排序

		text.Output(aprime);//输出结果

		text.Delete();//释放内存
		delete [] num;//释放内存
	}
	return 0;
}