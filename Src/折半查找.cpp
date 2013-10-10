// BinSearch.cpp : 岗位实践2-折半查找-程序框架
// 请在BinSearchKey函数内填入实现折半查找的代码

#include <iostream>
using namespace std;

#define MAXNUM 100

class BinSearch {
	public:
		BinSearch();					
		void CreateSequence(int *, int);	//生成有序序列
		int  BinSearchKey(int);				//折半查找关键字
											//以下是最终输出的结果
		int  BinSuccess;					//查找是否成功（1--成功，0--不成功）
		int  BinPos;						//查找位置（0表示不成功）
		int  BinCount;						//查找次数
	private:
		int  BinList[MAXNUM];				//有序表 
		int  MaxKeyCount;					//有序表长度
};

BinSearch::BinSearch()
{

}

void BinSearch::CreateSequence(int *r, int n) //冒泡排序
{
	int i, j, temp;

	MaxKeyCount = n;
	for (i=1; i<n; i++) {
	      if (r[i] < r[i-1]) {
	           temp = r[i];
	           for (j=i-1; j>=0; j-=1) if (temp<r[j]) r[j+1] = r[j]; else break;
	           r[j+1] = temp;
	      }
	}
	for (i=0; i<n; i++) BinList[i] = r[i];

/*	cout << "有序序列为：";
	for (i=0; i<n; i++) cout << BinList[i] << ", ";
	cout << endl << endl;*/

}

int BinSearch::BinSearchKey(int Key) //折半查找
{
	int Low, Mid, High;		//下界、中点、上界

	Low = 0;				//初始化下界
	High = MaxKeyCount-1;   //初始化上界
		
	BinSuccess = 0;			//初始化查找成功标志 （1--成功，0--不成功）
	BinPos = 0;				//初始化返回位置 （0表示不成功）
	BinCount = 0;			//初始化查找次数
	while (Low <= High) {   //折半查找，直至low>high时，查找失败
	//To do: 请在while循环内填入折半查找的代码，根据注释填入相应代码，也可以自行设计结构
		BinCount++;				   //查找次数加1
		Mid = (Low+High) / 2;	   //先确定中点位置					
							
		if (Key == BinList[Mid]) { //如果Key和中点值相等
			BinSuccess = 1;		   //设置查找成功标志为1，表示查找成功
			BinPos = Mid+1;		   //设置查找位置,表示第几个位置的值为Key
			break;				   //退出while循环，查找结束
		}

		if (Key < BinList[Mid]) High = Mid - 1;  //如Key的值小于中点值，修改上界

		else			        Low  = Mid + 1;  //否则，修改下界		
	}

	return(BinCount);       //返回查找次数
}



int main(int argc, char* argv[])
{
	int r[MAXNUM];
	int i, j, Key;
	int TestNo, SampleNo;							// 测试序列个数，序列大小

	BinSearch *BS = new BinSearch;					// 实例化折半查找

	cin >> TestNo;									// 输入测试次数
	for (i=0; i<TestNo; i++) {
		cin >> SampleNo;							// 输入样本数目
		for (j=0; j<SampleNo; j++) cin >> r[j];		// 输入样本数据，作顺序表

		BS->CreateSequence(r, SampleNo);            // 排序

		cin  >> Key;								// 输入1个查找数据
		BS->BinSearchKey(Key);                      // 查找

		cout << BS->BinSuccess << " " << BS->BinPos << " " 
			 << BS->BinCount << endl;	// 最终输出结果： 1）成功与否 2）若成功所在第几个值 3）查找次数
		}
	return 0;
}