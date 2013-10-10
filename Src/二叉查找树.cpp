// 二叉查找树，又称二叉排序树
// 请按照注释提示，实现其创建、插入、查找和删除操作

#include <iostream>
using namespace std;

#define MAXNUM 100

//树节点结构体
struct BiNode {  
	int 		data;			// 树节点值
	BiNode	*lChild, *rChild;	// 左右孩子
};

//二叉排序树 类
class BiSortTree {			
	public:
		BiSortTree();								//构造函数
		~BiSortTree();								//析构函数

		void CreateBST(int *r, int n);				//建立二叉排序树

		int  SearchBST(int k);						//查找结点

		void InsertBST(int k);						//插入结点

		void InOrderTravel();						//中序遍历排序树

		int	FindMin();								//查找排序树的最小值
		int FindMax();								//查找排序树的最大值

		void DeleteNode(int k);						//删除结点k

													
		int  BisSuccess;							//查找是否成功（1--成功，0--不成功）
		int  BisPos;								//查找位置（表示在BisCount层中的第几个位置（以完全二叉树为准，根结点为1结点））
		int  BisCount;								//查找次数（相当于树的层数）

	private:
		BiNode *root;								//根指针
		void DeleteTree(BiNode *s);					//删除一棵树s

		void SearchNode(BiNode *s, int k);			//从以s为根的树中查找一个结点k

		void InsertNode(BiNode *s, BiNode *q);	    //向以s为根的树插入一个结点q

		void InOrderTravel(BiNode *s);				//中序遍历以s为根节点的排序树

		int	FindMin(BiNode *s);						//查找以s为根节点的排序树的最小值
		int FindMax(BiNode *s);						//查找以s为根节点的排序树的最大值

		BiNode* DeleteNode(BiNode *s, int k);		//从以s为根节点的排序树删除结点k, 返回新树
};

// 构造函数
BiSortTree::BiSortTree() 
{
	root = new BiNode;							//生成空树
	root->data = NULL;							//根结点值为空
	root->lChild = NULL; 
	root->rChild = NULL; 
}

//析构函数
BiSortTree::~BiSortTree() 
{
	DeleteTree(root);							//删除所有结点
}

//函数DeleteTree： 删除以s为根节点的树, 析构整棵树
void BiSortTree::DeleteTree(BiNode *s)
{
	if (s == NULL) return;
	DeleteTree(s->lChild);						//删除左孩子
	DeleteTree(s->rChild);						//删除右孩子
	delete s;									//删除结点
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//公有函数CreateBST： 创建二叉排序树
void BiSortTree::CreateBST(int *r, int n) 
{
	int i;
	BiNode *s;

	root->data = r[0];			//赋根节点第一个值
	root->lChild = NULL;		//左孩子赋空
	root->rChild = NULL;		//右孩子赋空
	for (i=1; i<n; i++) {		//从第2个值开始，依次插入二叉排序树
		s = new BiNode;			//新建一个节点
		s->data   = r[i];		//把第i个值赋给新节点
		s->lChild = NULL;		//新节点左孩子赋空
		s->rChild = NULL;		//新节点右孩子赋空
		InsertNode(root, s);	//调用私有函数, 使用InsertNode函数插入新节点
	}
}

//公有函数InsertBST：插入新值到已知二叉排序树
void BiSortTree::InsertBST(int k) 
{
	BiNode *s;					

	s = new BiNode;				  //新建一个节点
	s->data = k;				  //赋新值k给新节点
	s->lChild = NULL;			  //新节点左孩子赋空
	s->rChild = NULL;			  //新节点右孩子赋空
	InsertNode(root, s);		  //调用私有函数, 使用InsertNode函数插入新节点
}

//私有函数InsertNode：插入新节点q到以s为根节点的树
void BiSortTree::InsertNode(BiNode *s, BiNode *q) 
{
	if (q->data < s->data) {						//如果s的值小于当前根节点
		if (!s->lChild==NULL)						//如果当前根节点有左子树
			InsertNode(s->lChild, q);				//往左子树插入结点
		else {										//else:当前根节点没有左子树
			s->lChild = q;							//把新节点s当做当前根节点的左孩子
			return;									//返回
		}
	}
	else {											//else: 如果s的值不小于当前根节点
		if (!s->rChild==NULL)						//如果当前根节点有右子树
			InsertNode(s->rChild, q);				//往右子树插入结点
		else {										//else: 当前根节点没有右子树
			s->rChild = q;							//把新节点s当做当前根节点的右孩子
			return;									//返回
		}
	}
}

//公有函数SearchBST: 在当前树中查找结点k
int BiSortTree::SearchBST(int k) 
{
	BisCount = 0;				//初始化查找次数为0
	BisPos = 1;					//初始化查找位置为1

	if (root->data == NULL) {   //如果当前树为空
		BisSuccess = 0;			//查找不成功
		return(0);				//返回
	}

	SearchNode(root, k);		//调用私有函数, 在以root为根节点的树中查找k, 使用SearchNode函数

	cout << BisSuccess << " " << BisCount << " " << BisPos << endl; // 输出结果

	return(BisSuccess);			//返回成功标志
}

//私有函数SearchNode: 从以s为根的树中查找一个结点k
void BiSortTree::SearchNode(BiNode *s, int k)
{
	BiNode *NextBiNode;					//下一个查找开始点

	BisCount++;							//查找次数加1

	if (s->data == k) {					//如果当前节点的值为k
		BisSuccess = 1;					//设置查找成功标志为成功
		return;							//返回
	}
	else {								//如果当前节点的值不为k
		if (s->data > k)				//如果k小于当前节点的值
		{
			BisPos = 2*BisPos-1;		//修改查找位置BisPos为当前节点的左孩子的位置, 其位置为当前位置的2倍减1
			NextBiNode = s->lChild;		//设置下一个查找点NextBiNode为当前节点的左孩子
		}
		else							//else，如果k不小于当前节点的值
		{
			BisPos = 2*BisPos;			//修改查找位置BisPos为当前节点的右孩子的位置, 其位置为当前位置的2倍
			NextBiNode = s->rChild;		//设置下一个查找点NextBiNode为当前节点的右孩子
		}
	}

	if (NextBiNode != NULL)				//如果下一个查找点NextBiNode，不为空
		SearchNode(NextBiNode, k);		//在以NextBiNode为根节点的树中查找k, 使用SearchNode函数
	else {								//else:下一个查找点NextBiNode为空
		BisSuccess = 0;					//设置查找标志BisSuccess为失败
		BisCount++;						//查找次数加1，因为事实上还需要在比较一次，我们提前处理
		InsertBST(k);					//根据动态查找表，查找不成功，需插入k到当前树，使用InsertBST函数
	}
}

//公有函数InOrderTravel: 中序遍历当前树
void BiSortTree::InOrderTravel()
{
	InOrderTravel(root);	//调用私有函数, 中序遍历以root为根节点的树
	cout << endl;
}

//私有函数InOrderTravel: 中序遍历以s为根节点的树
void BiSortTree::InOrderTravel(BiNode *s)
{
	if(s == NULL) return;

	//中序遍历
	if(s->lChild != NULL)
		InOrderTravel(s->lChild);

	cout << s->data << " ";

	if(s->rChild != NULL)
		InOrderTravel(s->rChild);
}

//公有函数FindMin: 查找当前树的最小值
int	BiSortTree::FindMin()
{
	return FindMin(root); //调用私有函数,查找以root为根节点的树的最小值
}

//私有函数FindMin: 查找以s为根节点的树的最小值
int	BiSortTree::FindMin(BiNode *s)
{
	if( s == NULL )					//如果为空树
		return NULL;				//返回空
	else if( s->lChild == NULL )	//如果左子树为空，则当前值为最小值
		return s->data;				//返回当前值
	else							//否则，左子树不空
		return FindMin(s->lChild);	//返回在左子树中找到的最小值，使用FindMin函数
}

//公有函数FindMax: 查找当前树的最大值
int	BiSortTree::FindMax()
{
	return FindMax(root); //调用私有函数,查找以root为根节点的树的最大值
}

//私有函数FindMax: 查找以s为根节点的树的最大值
int	BiSortTree::FindMax(BiNode *s)
{
	if( s == NULL )					//如果为空树
		return NULL;				//返回空
	else if( s->rChild == NULL )	//如果右子树为空，则当前值为最大值
		return s->data;				//返回当前值
	else							//否则，右子树不空
		return FindMax(s->rChild);	//返回在右子树中找到的最大值，使用FindMax函数
}

//公有函数DeleteNode: 从当前树中删除值k
void BiSortTree::DeleteNode(int k)
{
	root = DeleteNode(root, k); //调用私有函数DeleteNode, 从以root为根节点的树中删除k, 新树指针赋回root
}

//私有函数DeleteNode: 从以s为根节点的树中删除k, 返回新树指针
BiNode* BiSortTree::DeleteNode(BiNode *s, int k)
{
	if( s == NULL )											//如果s为空树
		return NULL;										//返回空指针
	else if( k < s->data )									//如果k小于当前节点值，则k在左子树
	{
		s->lChild = DeleteNode( s->lChild, k );				//从左子树中删除k，使用DeleteNode函数，新树指针赋回左子树
	}
	else if( k > s->data )  								//如果k大于当前节点值，则k在右子树
	{
        s->rChild = DeleteNode( s->rChild, k ); 			//从右子树中删除k，使用DeleteNode函数，新树指针赋回右子树
	}
    else													//else: k等于当前节点值，当前节点为删除节点
	if( s->lChild && s->rChild )							//如果被删除节点有两个孩子，则1.用它的直接前驱替换它，2.然后删除直接前驱
		{
			int temp = FindMax( s->lChild );				//找到直接前驱temp，直接前驱为左子树的最大值，使用FindMax私有函数
			s->data = temp;									//当前节点替换为直接前驱
			s->lChild = DeleteNode( s->lChild, temp );		//从左子树中删除直接前驱temp，使用DeleteNode函数，新树指针赋回左子树
		}
	else													//else: 被删除节点只有0或1个孩子
	{
		BiNode *tempNode = s;								//备份当前节点指针

		if( s->lChild == NULL )								//如果左子树为空，则右子树要么空，要么不空
			s = s->rChild;									//右子树赋给当前节点
		else if( s->rChild == NULL )						//else if: 如果右子树为空，则左子树要么空，要么不空
			s = s->lChild;									//左子树赋给当前节点

		delete tempNode;									//删除当前节点的备份tempNode
	}

	return s;												//返回新树
}


int main(int argc, char* argv[])
{
	int t[MAXNUM];
	int i, j, sKey,iKey, dKey;						//sKey：待查找值， iKey:待插入值， dKey：待删除值
	int TestNo, SampleNo;

	BiSortTree *BST = new BiSortTree;

	cin >> TestNo;									// 输入测试次数
	for (i=0; i<TestNo; i++) {
		cin >> SampleNo;							// 输入样本数目
		for (j=0; j<SampleNo; j++) cin >> t[j];		// 输入样本数据，作顺序表		
		cin  >> sKey >> iKey >> dKey;				//输入待查找sKey， 待插入iKey， 待删除dKey

		
		//1 建立二叉查找树操作
		BST->CreateBST(t, SampleNo);				//建立二叉查找树
		BST->InOrderTravel();						//输出中序遍历结果，有序序列
		cout << "Min Value:" << BST->FindMin() << endl;	//输出当前树的最小值
		cout << "Max Value:" << BST->FindMax() << endl;	//输出当前树的最大值
		////////////////////////////////////////////////////////////////////////////////////////////////
	
		//2 查找sKey操作
		BST->SearchBST(sKey);						//查找sKey
		BST->InOrderTravel();						//查找后中序遍历结果，注意查找不成功时插入，遍历结果有变化
		////////////////////////////////////////////////////////////////////////////////////////////////

		//3 插入iKey操作
		BST->InsertBST(iKey);						//插入iKey
		BST->InOrderTravel();						//插入后中序遍历结果
		BST->SearchBST(iKey);						//插入后查找iKey
		////////////////////////////////////////////////////////////////////////////////////////////////

		//4 删除dKey操作
		BST->DeleteNode(dKey);						//删除dKey
		BST->InOrderTravel();						//删除后中序遍历结果
		BST->SearchBST(dKey);						//删除后查找dKey
		////////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;
}